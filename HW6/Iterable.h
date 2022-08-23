#ifndef ITERABLE_H
#define ITERABLE_H

#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

namespace GTU
{
    /*Base  abstract Class with Pure VIrtual functions*/
template <typename T>
class Iterable
{
    virtual GTUIterator<T> begin() = 0;
    virtual GTUIterator<T> end() = 0;
    virtual bool empty() const = 0;
    virtual int  size() const = 0 ;
    virtual void clear() = 0;
    virtual void erase(GTUIteratorConst<T> index) = 0;
    virtual GTUIteratorConst<T> cbegin() = 0;
    virtual GTUIteratorConst<T> cend() = 0;

};


}

#endif // !ITERABLE_H