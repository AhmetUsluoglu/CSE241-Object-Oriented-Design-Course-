#ifndef GTUARRAY_H
#define GTUARRAY_H

#include <memory>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Iterable.h"


namespace GTU
{
    
// Custom containers for arrays    
template <class T>
class GTUArray : public Iterable<T>
{
    public:
    /// Constructors for class
    GTUArray();
    GTUArray(int SizeOfArr);
    GTUArray(GTUArray& NewArr);
    GTUArray(GTUArray&& NewArr);

    GTUIterator<T> begin()  {return arr.get();}; // returns the begining of the array
    GTUIterator<T> end()    {return arr.get()+Size;};   // returns the end of the array
    
    bool empty() const; // returns true if array is empty
    int  size()  const      {return Size;}; // returns size
    void clear();   // removes all elements from array
    void erase(GTUIteratorConst<T> index);  // removes an element from an index
    
    GTUIteratorConst<T> cbegin(){return arr.get();};    // returns the begining of the array
    GTUIteratorConst<T> cend()  {return arr.get()+Size;};   // returns the end of the array
    
    T& operator[] (int index)   {return arr.get()[index];}; // return element at given index

    GTUArray& operator= (GTUArray& right);  // Overloaded assignment operators
    GTUArray& operator= (GTUArray&& right);

    void fill(T def_Elm);
    T& back()   {return *(this->end());};   // returns the begining of the array
    T& front()  {return *(this->begin());}; // returns the end of the array
    T& at(int index)    {return *(this->begin()+index-1);}; // return element at given index

    private:
    std :: shared_ptr<T> arr;
    int Size;
};


}
#include "GTUArray.cpp"
#endif 