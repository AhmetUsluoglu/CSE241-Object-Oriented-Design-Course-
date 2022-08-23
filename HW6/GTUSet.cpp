#include "GTUSet.h"

// Implementation file for GTUSet.h 
namespace GTU
{
//////////////////// CONSTRUCTORS ////////////////////////////
template<class T>
GTUSet<T> :: GTUSet()
{
    set = nullptr;
    Size = 0;
}; 

template<class T>
GTUSet<T> :: GTUSet(int element)
{
    Size = 0;
    add(element);
};

template<class T>
GTUSet<T> :: GTUSet(GTUSet& Newset)
{
    Size = Newset.Size;
    std :: shared_ptr<T> temp(new T[Size]);
    for (int i = 0; i < Size; i++)
    {
        temp.get()[i] = Newset.set.get()[i]; 
    }
    set = temp;
}; 

template<class T>
GTUSet<T> :: GTUSet(GTUSet&& Newset)
{
    Size = Newset.Size;
    set = Newset.set;
    Newset.set.reset();
}
//////////////////// MEMBER FUNCTIONS ////////////////////////////
template<class T>
bool GTUSet<T> :: empty() const
{
    if (Size == 0) return true;
    return false;
};

template<class T>
void GTUSet<T> :: clear()
{
    Size = 0;
    set.reset();
};

template <class T>
void GTUSet<T> :: erase(GTUIteratorConst<T> index)
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
        set = temp;
        Size--;
    }
};

template <class T>
GTUSet<T>& GTUSet<T> :: operator= (GTUSet& right)
{
    if(Size != right.Size)
    {
        set.reset();
        std :: shared_ptr<T> temp(new T[right.Size]);
        set = temp;
    }
    Size = right.Size;
    for (int i = 0; i < Size; i++)
    {
        set.get()[i] = right.set.get()[i];
    }
    
    return *this;
};

template <class T>
GTUSet<T>& GTUSet<T> :: operator= (GTUSet&& right)
{
    Size = right.Size;
    set = right.set;
    right.set.reset();
}

template <class T>
void GTUSet<T> :: add(T element)
{
    if(check(element) != false)
    {
        std :: shared_ptr<T> temp(new T[Size+2]);
        for (int i = 0; i < Size; i++)
        {
            temp.get()[i] = set.get()[i];
        }
        temp.get()[Size] = element;
        set = temp;
        Size++;
    }
};

template <class T>
bool GTUSet<T> :: check(T element)
{
    for (int i = 0; i < Size; ++i)
    {
        if(set.get()[i] == element) return false;
    }
    return true;
};

template <class T>
int GTUSet<T> :: search(T element)
{
    for (int i = 0; i < Size; i++)
    {
        if(set.get()[i] == element) return i;
    }
    return -1;
}

template <class T>
void GTUSet<T> :: deleteElm(T element)
{
    if(search(element) != -1)
    {
        std :: shared_ptr<T> temp(new T[Size-1]);
        for (int i = 0 , j = 0; i < Size; i++)
        {
            if(set.get()[i] != element)
            {
                temp.get()[j] = set.get()[i];
                j++;
            }
        }
        Size--;
        set = temp;
    }
}

template <class T>
GTUSet<T> GTUSet<T> :: intersection (GTUSet rightset)
{
    GTUSet<T> temp;
    for (auto i = 0; i < Size; i++)
    {
        for (int j = 0; j < rightset.Size; j++)
        {
            if(set.get()[i] == rightset.set.get()[j])
            {temp.add(set.get()[i]);}
        }
    }
    return temp;
}

template <class T>
GTUSet<T> GTUSet<T> :: unions (GTUSet rightset)
{
    return rightset;
}

}