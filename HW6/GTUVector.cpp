#include "GTUVector.h"

namespace GTU
{
//////////////////// CONSTRUCTORS ////////////////////////////
template<class T>
GTUVector<T> :: GTUVector()
{
    Size = 0;
    Capacity = 2;
    std :: shared_ptr<T> temp(new T[Capacity]);
    vec = temp;
}; 

template<class T>
GTUVector<T> :: GTUVector(int SizeOfvec)
{
    Size = SizeOfvec;
    std :: shared_ptr<T> temp(new T[Capacity]);
    vec = temp;
    Capacity = SizeOfvec * 2;
};

template<class T>
GTUVector<T> :: GTUVector(GTUVector& Newvec)
{
    Size = Newvec.Size;
    Capacity = Size *2;
    std :: shared_ptr<T> temp(new T[Size]);
    for (int i = 0; i < Size; i++)
    {
        temp.get()[i] = Newvec.vec.get()[i]; 
    }
    vec = temp;
}; 

template<class T>
GTUVector<T> :: GTUVector(GTUVector&& Newvec)
{
    Size = Newvec.Size;
    Capacity = Size * 2;
    vec = Newvec.vec;
    Newvec.vec.reset();
}
//////////////////// MEMBER FUNCTIONS ////////////////////////////
template<class T>
bool GTUVector<T> :: empty() const
{
    if (Size == 0) return true;
    return false;
};

template<class T>
void GTUVector<T> :: clear()
{
    Size = 0;
    Capacity = 2;
    vec.reset();
};

template <class T>
void GTUVector<T> :: erase(GTUIteratorConst<T> index)
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
        if(Size <= Capacity/2) Capacity = Capacity / 2; 
        std :: shared_ptr<T> temp(new T[Capacity]);
        for(auto i = cbegin(), j = 0; i != cend(); ++i, ++j)
        {
            if(i == index) ++i;
            temp.get()[j] = *i;
        }
        vec = temp;
        Size--;
    }
};

template <class T>
GTUVector<T>& GTUVector<T> :: operator= (GTUVector& right)
{
    
    if(Size != right.Size)
    {
        vec.reset();
        Capacity = right.Size*2;
        std :: shared_ptr<T> temp(new T[Capacity]);
        vec = temp;
    }
    Size = right.Size;
    for (int i = 0; i < Size; i++)
    {
        vec.get()[i] = right.vec.get()[i];
    }
    
    return *this;
};

template <class T>
GTUVector<T>& GTUVector<T> :: operator= (GTUVector&& right)
{
    Size = right.Size;
    Capacity = Size * 2;
    vec = right.vec;
    right.vec.reset();
    return *this;
}

template<class T>
void GTUVector<T> :: push_back(T element)
{
    if (Size == Capacity)
    {
        *this = GTUVector(*this);
    }
    vec.get()[Size] = element;
    Size++;
};

template<class T>
void GTUVector<T> :: pop_back()
{   
    if (Size != 0)
    {
        vec.get()[Size-1] = 0;
        Size--;
        if (Size <= Capacity / 2) Capacity /= 2;
    }
};

}