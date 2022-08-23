#ifndef GTUIteratorConst_h
#define GTUIteratorConst_h

namespace GTU
{

template<class T>
class GTUIteratorConst
{
    private:
    const T* ptr;

    public:

    GTUIteratorConst<T>();
    GTUIteratorConst<T>(const T* newptr);

    const T* getPointer();
    GTUIteratorConst& operator= (const GTUIteratorConst& right);    /*Overloaded Assignment Operator*/
    
    const T& operator* ();      //Overloaded Dereffrenece Operator
    const T* operator-> ();      //Overloaded Reach Operator   

    GTUIteratorConst& operator+ (int add);  //Overloaded sum Operator
    GTUIteratorConst& operator- (int sub);  //Overloaded substraction Operator
    
    bool operator== (GTUIteratorConst right) const; //Overloaded equal Operator
    bool operator!= (GTUIteratorConst right) const; //Overloaded not equal Operator

    GTUIteratorConst& operator++ ();    //Overloaded pre increment Operator
    GTUIteratorConst operator++ (int);  //Overloaded post increment Operator
    GTUIteratorConst& operator-- ();    //Overloaded pre decrement Operator
    GTUIteratorConst operator-- (int);  //Overloaded post decrement Operator
    
};

}
#include "GTUIteratorConst.cpp"

#endif