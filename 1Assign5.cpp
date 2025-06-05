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
       void append(int x);
       
};
void Array::append(int x)
{
    if(ptr==nullptr)
      throw ARRAT_NOT_CREATED;
    if(lastIndex==capacity-1)
       throw ARRAY_OVERFLOW;
    lastIndex++;      
    ptr[lastIndex]=x;  
}