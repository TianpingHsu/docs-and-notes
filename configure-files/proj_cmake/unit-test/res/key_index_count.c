#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Name {
        char name[64];
        int key;
};

struct Name names[18250];
struct Name tmp[18250];

void test1()
{
        FILE *fp = fopen("./names.txt", "r");
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        int count = 0;
        while ((read = getline(&line, &len, fp)) != -1) {
                strncpy(names[count].name, line, sizeof(names[count].name));
                names[count].key = names[count].name[0] - 'A' + 1;
                printf("%d:%s", names[count].key, names[count].name);
                if (read == 5) printf("%s", names[count].name);
                count ++;
        }
        //printf("%d\n", count);
        int idx[27] = {0};
        for (int i = 0; i < count; i++) {
                idx[names[i].key]++;
        }
        for (int i = 0; i < 26; i ++) {
                idx[i + 1] += idx[i];
        }
        for (int i = 0; i < count; i++) {
                tmp[idx[names[i].key - 1]++] = names[i];
        }
        for (int i = 0; i < count; i++) {
                //printf("%d:%s", tmp[i].key, tmp[i].name);
        }
        fclose(fp);
        if (line) free(line);
}

//struct Name {
//char name[64];
//int key;
//};
//struct Name names[18250];
//struct Name tmp[18250];

struct Name* radix_sort(struct Name *dst, unsigned int count, unsigned int significant_bit)
{
        unsigned int groups[27] = {0}, *idx = NULL;
        for (unsigned int i = 0; i < count; i++) {  // cal frequency
                int c = dst[i].name[significant_bit];
                if (c >= 'A' && c <= 'Z') c = c - 'A' + 1;
                else c = c - 'a' + 1;
                dst[i].key = c;
                groups[dst[i].key]++;
        }
        idx = groups;
        for (int i = 0; i < 26; i++) {
                idx[i + 1] += idx[i];
        }
        for (int i = 0; i < count; i++) {
                int index = idx[dst[i].key - 1]++;
                tmp[index] = dst[i];
        }
        for (int i = 0; i < count ; i++) {  // copy
                dst[i] = tmp[i];
        }
        return dst;
}


void test2()
{
        FILE *fp = fopen("./names.txt", "r");
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        int count = 0;
        int INTERESTED_LEN = 6;
        while ((read = getline(&line, &len, fp)) != -1) {
                if (read == INTERESTED_LEN) {
                        strncpy(names[count].name, line, sizeof(names[count].name));
                        names[count].key = names[count].name[0] - 'A' + 1;
                        //printf("%s", names[count].name);
                        count ++;
                }
        }

        for (int i = INTERESTED_LEN - 2; i >= 0; i--) {
                radix_sort(names, count, i);
        }
        for (int i = 0; i < count; i++) {
                printf("%s", names[i].name);
        }

        fclose(fp);
        if (line) free(line);
}

int main()
{
        test2();
        return 0;
}
