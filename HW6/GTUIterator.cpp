#include "GTUIterator.h"
namespace GTU
{

/////////////////////////////// CONSTRUCTORS //////////////////////////
template<class T>
GTUIterator<T> :: GTUIterator(){ptr = nullptr;};

template<class T>
GTUIterator<T> :: GTUIterator(T* newptr) : ptr(newptr){};

template<class T>
T* GTUIterator<T> :: getPointer(){return ptr;};


/////////////////////////////// MEMBEr Functions /////////////////////////

/*Overloaded Assignment Operator*/
template<class T>
GTUIterator<T>& GTUIterator<T> :: operator= (const GTUIterator& right)
{
    ptr = right.ptr;
    return *this;
};

/*Overloaded Derefferenece Operator*/
template<class T>
T& GTUIterator<T> :: operator* ()
{
    return *ptr;
};


/*Overloaded reach Operator*/
template<class T>
T* GTUIterator<T> :: operator-> ()
{
    return &(*ptr);
};

/*Overloaded sum Operator*/
template<class T>
GTUIterator<T>& GTUIterator<T> ::  operator+ (int add)
{
    ptr = ptr + add;
    return *this;
};

/*Overloaded substraction Operator*/
template<class T>
GTUIterator<T>& GTUIterator<T> ::  operator- (int sub)
{
    ptr = ptr - sub;
    return *this;
};


/*Overloaded equality Operator*/
template<class T>
bool GTUIterator<T> :: operator==(GTUIterator right) const
{
    if (ptr == right.ptr)   return true;
    return false;
};

/*Overloaded Not Equal Operator*/
template<class T>
bool GTUIterator<T> :: operator!=(GTUIterator right) const
{
    return !(this->ptr == right.ptr);
};

/*Overloaded pre increment Operator*/
template<class T>
GTUIterator<T>& GTUIterator<T> ::   operator++ ()
{   
    ptr++;
    return *this; 
};

/*Overloaded post increment Operator*/
template<class T>
GTUIterator<T> GTUIterator<T> ::   operator++ (int)
{
    GTUIterator temp (ptr);
    ptr++;
    return temp;
};

/*Overloaded pre decrement Operator*/
template<class T>
GTUIterator<T>& GTUIterator<T> ::   operator-- ()
{
    ptr--;
    return *this;
};

/*Overloaded post decrement Operator*/
template<class T>
GTUIterator<T> GTUIterator<T> ::   operator-- (int)
{
    GTUIterator temp(ptr);
    ptr--;
    return temp;
};


}