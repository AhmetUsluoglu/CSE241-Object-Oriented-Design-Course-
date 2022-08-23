#include "GTUArray.h"

namespace GTU
{
//////////////////// CONSTRUCTORS ////////////////////////////
template<class T>
GTUArray<T> :: GTUArray()
{
    arr = nullptr;
    Size = 0;
}; 

template<class T>
GTUArray<T> :: GTUArray(int SizeOfArr)
{
    Size = SizeOfArr;
    std :: shared_ptr<T> temp(new T[Size]);
    arr = temp;
};

template<class T>
GTUArray<T> :: GTUArray(GTUArray& NewArr)
{
    Size = NewArr.Size;
    std :: shared_ptr<T> temp(new T[Size]);
    for (int i = 0; i < Size; i++)
    {
        temp.get()[i] = NewArr.arr.get()[i]; 
    }
    arr = temp;
}; 

template<class T>
GTUArray<T> :: GTUArray(GTUArray&& NewArr)
{
    Size = NewArr.Size;
    arr = NewArr.arr;
    NewArr.arr.reset();
}
//////////////////// MEMBER FUNCTIONS ////////////////////////////
template<class T>
bool GTUArray<T> :: empty() const
{
    if (Size == 0) return true;
    return false;
};

template<class T>
void GTUArray<T> :: clear()
{
    Size = 0;
    arr.reset();
};

template <class T>
void GTUArray<T> :: erase(GTUIteratorConst<T> index)
{
    int flag = 0;
    
    for (auto i = cbegin(); i != cend(); i++)
    {
        if (i == index)
        {
            flag = 1;
            break;
        } 
    }
    
    if(flag)
    {
        std :: shared_ptr<T> temp(new T[Size-1]);
        for(auto i = cbegin(), j = 0; i != cend(); ++i, ++j)
        {
            if(i == index) ++i;
            temp.get()[j] = *i;
        }
        arr = temp;
        Size--;
    }
};

template <class T>
GTUArray<T>& GTUArray<T> :: operator= (GTUArray& right)
{
    if(Size != right.Size)
    {
        arr.reset();
        std :: shared_ptr<T> temp(new T[right.Size]);
        arr = temp;
    }
    Size = right.Size;
    for (int i = 0; i < Size; i++)
    {
        arr.get()[i] = right.arr.get()[i];
    }
    
    return *this;
};

template <class T>
GTUArray<T>& GTUArray<T> :: operator= (GTUArray&& right)
{
    Size = right.Size;
    arr = right.arr;
    right.arr.reset();
}

template <class T>
void GTUArray<T> :: fill(T def_Elm)
{
    for (auto i = 0; i < Size; i++)
    {
        arr.get()[i] = def_Elm;
    }
};

}