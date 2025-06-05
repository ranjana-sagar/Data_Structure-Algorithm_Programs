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
       void insert(int index,int val);
       void edit(int index,int val);
       void Delete(int index,int val);
       bool isFull();
       int getElement(int index);
       int totalElements();
       ~Array();
       int findElement(int val);
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
bool Array::isEmpty()
{
    if(ptr==nullptr)
       throw ARRAT_NOT_CREATED;
    return lastIndex==-1;
}
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
void Array::append(int x)
{
    if(ptr==nullptr)
      throw ARRAT_NOT_CREATED;
    if(lastIndex==capacity-1)
       throw ARRAY_OVERFLOW;
    lastIndex++;      
    ptr[lastIndex]=x;  
}
void Array::insert(int index,int val)
{
    if(ptr==nullptr)
      throw ARRAT_NOT_CREATED;
    if(lastIndex==capacity-1)
       throw ARRAY_OVERFLOW;      
    if(index<0||index>lastIndex+1)
       throw INVALID_INDEX;
    //////////////////////////////////////
    if(index<=lastIndex)
    {
        int i=lastIndex;
        while(i>=index)
        {
            ptr[i+1]=ptr[i];
            i--;
        }
        ptr[index]=val;
        lastIndex++;
    }  
    ptr[index]=val,lastIndex++; 
}
void Array::edit(int index,int val)
{
    if(ptr==nullptr)
      throw ARRAT_NOT_CREATED;    
    if(index<0||index>lastIndex)
       throw INVALID_INDEX;
    ///////////////////////////////////////
    ptr[index]=val;
}
void Array::Delete(int index,int val)
{
     if(ptr==nullptr)
      throw ARRAT_NOT_CREATED;
    if(lastIndex==capacity-1)
       throw ARRAY_OVERFLOW;      
    if(index<0||index>lastIndex)
       throw INVALID_INDEX;
    ///////////////////////////////////////
    int i=index;
    for(i,i<lastIndex;i++;)
    {
        ptr[i]=ptr[i+1];
    }
    lastIndex--;
}
bool Array::isFull()
{
    if(ptr==nullptr)
      throw ARRAT_NOT_CREATED;
    return lastIndex==capacity-1;
}
int Array::getElement(int index)
{
    if(ptr==nullptr)
      throw ARRAT_NOT_CREATED;    
    if(index<0||index>lastIndex)
       throw INVALID_INDEX;
    /////////////////////////////////
    return ptr[index];   
}
int Array::totalElements()
{
    if(ptr==nullptr)
      throw ARRAT_NOT_CREATED;   
    return lastIndex+1;
}
Array::~Array()
{
    if(ptr!=nullptr)
       delete []ptr;
}
int Array::findElement(int val)
{
       int i;
        for(i=0;i<=lastIndex;i++)
            if(ptr[i]==val);
                return i;
        return -1;        
}

int main()
{
    Array obj(5);
    
    return 0;
}