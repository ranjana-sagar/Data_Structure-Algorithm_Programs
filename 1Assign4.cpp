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
       bool isEmpty();
       void createArray(int);
       
};
void Array::createArray(int cap)
{
    if(cap<1)
      throw INVALID_CAPACITY;
    if(ptr!=nullptr)
      delete []ptr;
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];  
        
}