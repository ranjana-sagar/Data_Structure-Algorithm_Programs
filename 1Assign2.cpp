#include<iostream>
using namespace std;
#define INVALID_CAPACITY 1
#define ARRAT_NOT_CREATED 2
#define ARRAY_OVERFLOW 3
#define INVALID_INDEX 4
class Array
{
    private:
       int capacity,lastIndex;
       int*ptr=nullptr;
    public:
       Array();
       Array(int cap);   
};
Array::Array():capacity(0),lastIndex(-1){ptr=nullptr;}
Array::Array(int cap):capacity(cap),lastIndex(-1),ptr(nullptr)
{
    if(capacity<1)
    {
       capacity=0;
       throw INVALID_CAPACITY;
    }
    ptr=new int[capacity];
    if(ptr==nullptr)
    {
        cout<<"Memory Allocation is failed."<<endl;
        exit(0);
    }
}   