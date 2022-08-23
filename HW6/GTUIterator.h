#ifndef GTUIterator_h
#define GTUIterator_h

namespace GTU
{

/*Iterator CLass for our custom containers*/
template<class T>
class GTUIterator
{
    private:
    T* ptr;

    public:
    /*I took this part from internet because it did not work otherwise*/
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;  
    using reference         = T&;  
    
    /*Iterator Class has constructors and overload operators like normal pointers have*/
    GTUIterator<T>();
    GTUIterator<T>(T* newptr);

    T* getPointer();
    GTUIterator& operator= (const GTUIterator& right);
    
    T& operator* ();
    T* operator-> ();

    GTUIterator& operator- (int sub);
    GTUIterator& operator+ (int add);

    
    bool operator== (GTUIterator right) const;
    bool operator!= (GTUIterator right) const;

    GTUIterator& operator++ ();
    GTUIterator operator++ (int);
    GTUIterator& operator-- ();
    GTUIterator operator-- (int);
    
};

}
#include "GTUIterator.cpp"

#endif