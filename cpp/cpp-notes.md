

## perfect forwarding



## 封装后的成本
没有  
C++在布局以及存取时间上主要的额外负担是由virtual引起的:
* virtual function
* virtual base class


## The C++ Object Model
1. virtual table (pointers to virtual functions)
2. vptr

* non-static data members  -> in class object
* static members and non-static member functions  -> outside class object


## virtual inheritance
在虚拟继承中，base class 不管在继承链中被派生多少次，永远都只会存在一个实体  



