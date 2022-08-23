#include "GTUIteratorConst.h"
namespace GTU
{


template<class T>
GTUIteratorConst<T> :: GTUIteratorConst(){ptr = nullptr;};

template<class T>
GTUIteratorConst<T> :: GTUIteratorConst(const T* newptr) : ptr(newptr){};

template<class T>
const T* GTUIteratorConst<T> :: getPointer(){return ptr;};

template<class T>
GTUIteratorConst<T>& GTUIteratorConst<T> :: operator= (const GTUIteratorConst& right)
{
    ptr = right.ptr;
    return *this;
};

template<class T>
const T& GTUIteratorConst<T> :: operator* ()
{
    return *ptr;
};

template<class T>
const T* GTUIteratorConst<T> :: operator-> ()
{
    return &(*ptr);
};

template<class T>
GTUIteratorConst<T>& GTUIteratorConst<T> ::  operator+ (int add)
{
    ptr = ptr + add;
    return *this;
};

template<class T>
GTUIteratorConst<T>& GTUIteratorConst<T> ::  operator- (int sub)
{
    ptr = ptr - sub;
    return *this;
};

template<class T>
bool GTUIteratorConst<T> :: 

operator==(GTUIteratorConst right) const
{
    if (ptr == right.ptr)   return true;
    return false;
};

template<class T>
bool GTUIteratorConst<T> :: operator!=(GTUIteratorConst right) const
{
    return !(this->ptr == right.ptr);
};

template<class T>
GTUIteratorConst<T>& GTUIteratorConst<T> ::   operator++ ()
{   
    ptr++;
    return *this; 
};

template<class T>
GTUIteratorConst<T> GTUIteratorConst<T> ::   operator++ (int)
{
    GTUIteratorConst temp (ptr);
    ptr++;
    return temp;
};

template<class T>
GTUIteratorConst<T>& GTUIteratorConst<T> ::   operator-- ()
{
    ptr--;
    return *this;
};

template<class T>
GTUIteratorConst<T> GTUIteratorConst<T> ::   operator-- (int)
{
    GTUIteratorConst temp(ptr);
    ptr--;
    return temp;
};


}