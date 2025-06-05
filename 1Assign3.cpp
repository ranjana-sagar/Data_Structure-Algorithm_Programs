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
};
bool Array::isEmpty()
{
    if(ptr==nullptr)
       throw ARRAT_NOT_CREATED;
    return lastIndex==-1;
}       