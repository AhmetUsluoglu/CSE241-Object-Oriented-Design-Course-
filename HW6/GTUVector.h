#ifndef GTUVector_H
#define GTUVector_H

#include <memory>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Iterable.h"


namespace GTU
{
    
 // Custom containers for vectors    
template <class T>
class GTUVector : public Iterable<T>
{
    public:
    /// Constructors for class
    GTUVector();
    GTUVector(int SizeOfvec);
    GTUVector(GTUVector& Newvec);
    GTUVector(GTUVector&& Newvec);

    GTUIterator<T> begin()  {return vec.get();};    // returns the begining of the array
    GTUIterator<T> end()    {return vec.get()+Size;};// returns the end of the array
    
    bool empty() const; // returns true if array is empty
    void clear();       // removes all elements from array
    int  size()  const      {return Size;}; // returns size
    void erase(GTUIteratorConst<T> index);  // removes an element from an index
    
    GTUIteratorConst<T> cbegin(){return vec.get();};    // returns the begining of the array
    GTUIteratorConst<T> cend()  {return vec.get()+Size;};// returns the end of the array
    
    T& operator[] (int index)   {return vec.get()[index];}; // return element at given index

    GTUVector& operator= (GTUVector& right);    // Overloaded assignment operators
    GTUVector& operator= (GTUVector&& right);

    int capacity(){return Capacity;}; // returns capacity
    int max_size(){return Capacity;}; // returns capacity
    void push_back(T element);      // adds element to the end
    void pop_back();        // removes element from last

    T& back()   {return *(this->end()-1);}; // returns the end of the array
    T& front()  {return *(this->begin());}; // returns the begining of the array
    T& at(int index)    {return *(this->begin()+index-1);}; // return element at given index

    private:
    std :: shared_ptr<T> vec;
    int Size , Capacity;
};


}
#include "GTUVector.cpp"
#endif 