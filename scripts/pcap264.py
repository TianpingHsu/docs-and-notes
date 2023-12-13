#!/usr/bin/env python
import sys
import dpkt
import struct
import binascii

f = open(sys.argv[1], 'rb')

pcap = dpkt.pcap.Reader(f)
fdH264 = {}
skipcnt = 0
firstkeyframe = 0
rtpseq = -1
h264pt=[96,97,98,99,107,105,109,102,101,100,104,108,119]
for ts, buf in pcap:
    #print len(buf)
    eth = dpkt.ethernet.Ethernet(buf)
    #print eth.data.__class__.__name__,ts
    #print eth.data.__class__.__name__
    if eth.data.__class__.__name__=='IP' or eth.data.__class__.__name__ =='str':
            ip = eth.data
            if eth.data.__class__.__name__ =='str':
                ip = dpkt.ip.IP(buf)
            #dstipaddr='%d.%d.%d.%d'%tuple(map(ord,list(map(chr, ip.dst))))
            #srcipaddr='%d.%d.%d.%d'%tuple(map(ord,list(map(chr, ip.src))))
            srcipaddr='%d.%d.%d.%d'%tuple(map(ord,list(ip.src)))
            dstipaddr='%d.%d.%d.%d'%tuple(map(ord,list(ip.dst)))
            testdata=[0x41,0x82]
            nalhead=0x00000001
            #print "0x%08x"%nalhead
            #print testdata[1]&0x1F,

            #out.write(struct.pack('!I',nalhead))
            #out.close()
            if ip.data.__class__.__name__=='UDP':
              udp = ip.data

              try:
                            rtp = dpkt.rtp.RTP(udp.data)
                            print (rtp.pt)
                            if rtp.pt in h264pt :#and '192.168.122.154' == srcipaddr:
                                #print rtp.seq,rtpseq
                                if rtpseq == -1:
                                   pass
                                elif (rtpseq +1) != rtp.seq:
                                   #print '!!!!!!!!!!  rtp cur seq:%d  pre seq:%d !!!!!!!!!!!!!!'%(rtp.seq, rtpseq)
                                   print(rtp.seq)


                                rtpseq = rtp.seq
                                #print 'rtpseq %d'%rtpseq

                                try:
                                    F=(ord(rtp.data[0])>>7)&0x1
                                    NRI=(ord(rtp.data[0])>>5)&0x3
                                    TYPE=ord(rtp.data[0])&0x1F

                                    #print '%s to %s F:%d NRI:%d type:%d '%(srcipaddr,dstipaddr,F,NRI,TYPE)

                                    filename='%sto%s.h264'%(srcipaddr,dstipaddr)
                                    try:
                                      if fdH264[filename]:
                                        pass
                                    except:
                                       fdH264[filename] = open(filename,'w')

                                    #if firstkeyframe == 0 and TYPE != 7 :
                                    #       continue

                                    firstkeyframe = 1
                                    #print 'TYPE %d'%TYPE
                                    if TYPE==28:#FU-A
                                      S=(ord(rtp.data[1])>>7)&0x1
                                      E=(ord(rtp.data[1])>>6)&0x1
                                      R=(ord(rtp.data[1])>>5)&0x1
                                      NALTYPE=(ord(rtp.data[0]) & 0xe0) | (ord(rtp.data[1] )& 0x1f)
                                     # print S,E,R,hex(NALTYPE)
                                      if S == 1:
                                         fdH264[filename].write(struct.pack('!I',nalhead))

                                         fdH264[filename].write(struct.pack('B',int(NALTYPE)))

                                         fdH264[filename].write(rtp.data[2:])
                                         #print binascii.b2a_hex(rtp.data[:10])
           #                                      print "start nal pack"
                                      elif E == 1:
            #                                     print "end nal pack"
                                         fdH264[filename].write(rtp.data[2:])
                                      else:
                                         fdH264[filename].write(rtp.data[2:])
                                    elif TYPE == 24: #STAP-A
                                        datalen = len(rtp.data)
                                        #print 'stap-a len:%d-------------'%datalen
                                        print(datelen)

                                        datalen = datalen - 1

                                        offset = 1
                                        while datalen >= 2:

                                            nalSize = (ord(rtp.data[offset]) << 8) | ord(rtp.data[offset+1]);
                                            #print 'nalSize len:%d %d'%(nalSize,datalen)
                                            if datalen < nalSize + 2 :
                                                #print 'Discarding malformed STAP-A packet'
                                                break;
                                            fdH264[filename].write(struct.pack('!I',nalhead))
                                            fdH264[filename].write(rtp.data[offset+2:offset+2+nalSize])
                                            #print binascii.b2a_hex(rtp.data[offset+2:offset+2+1])

                                            offset += 2 + nalSize;
                                            datalen -= 2 + nalSize;

                                    else:

                                      #print hex(ord(rtp.data[0]) )
                                      fdH264[filename].write(struct.pack('!I',nalhead))
                                      #print binascii.b2a_hex(rtp.data[0:1])
                                      fdH264[filename].write(rtp.data)
                                except:
                                        continue
              #print rtp.cc,rtp.m,rtp.p,rtp.pt,rtp.version,rtp.x
              #print hex(rtp.ssrc), rtp.ts, len(rtp.data), binascii.b2a_hex(rtp.data[:2])


              except dpkt.dpkt.NeedData:
                 continue
              except dpkt.dpkt.UnpackError:
                 continue


for i in fdH264:
   fdH264[i].close()
f.close()

