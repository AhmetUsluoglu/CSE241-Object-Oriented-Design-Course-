#ifndef GTUSet_H
#define GTUSet_H

#include <memory>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Iterable.h"


namespace GTU
{
    
    
template <class T>
class GTUSet : public Iterable<T>
{
    public:
    GTUSet();
    GTUSet(int SizeOfset);
    GTUSet(GTUSet& Newset);
    GTUSet(GTUSet&& Newset);

    GTUIterator<T> begin()  {return set.get();}; // returns the begining of the set
    GTUIterator<T> end()    {return set.get()+Size;}; // returns the end of the set
    
    bool empty() const; // Returns true if set is empty
    int  size()  const      {return Size;}; //returns size
    void clear();   // Removes all elements from set
    void erase(GTUIteratorConst<T> index); //removes 1 element from set at given index
    
    GTUIteratorConst<T> cbegin(){return set.get();};    // returns the begining of the set
    GTUIteratorConst<T> cend()  {return set.get()+Size;};   // returns the end of the set
    
    T& operator[] (int index)   {return set.get()[index];};  // Reach operator

    GTUSet& operator= (GTUSet& right);  //Overloaded Assignment opperators
    GTUSet& operator= (GTUSet&& right);

    void add(T element);    // Adds an elemennt to the set
    void deleteElm(T element);  // Deletes an element from set
    int search(T element);      // Serachs an element from set
    GTUSet intersection (GTUSet rightset);  // Returns intersection of 2 sets
    GTUSet unions (GTUSet rightset); // Returns union set of 2 sets


    private:
    std :: shared_ptr<T> set;
    int Size;
    bool check(T element); // Checks if the element is in the set
};


}
#include "GTUSet.cpp"
#endif 