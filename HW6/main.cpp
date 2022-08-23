#include "GTUArray.h"
#include "GTUSet.h"
#include "GTUVector.h"
#include "GTUIterator.h"
#include "GTUIteratorConst.h"

//#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;
using namespace GTU;

// TEST file for our containers

template <class T>
void print(T element){cout << element << endl;};

int main()
{
    int j = 0;
    ////////////////////////////////// TESTING ARRAYS ////////////////////////////////////////////
    cout << "\t\t\t\tARRAYS\n";
    GTUArray<int> a1(5), a2 , a3(4) , a4(5);
    
    cout << "A1 array is empty and it's Size is " << a1.size() << endl;
    for (int i = 0; i < a1.size(); i++)
    {
        cout << i << " element is " << a1[i] << endl;
    }

    cout << "\n\nAdding 3,2,1,7,4 to a1 array\n";
    a1[4] = 3;
    a1[3] = 2;
    a1[2] = 1;
    a1[1] = 7;
    a1[0] = 4;
    cout << "A1 array's elements    \n\n";
    for (int i = 0; i < a1.size(); i++)
    {
        cout << i << " element is " << a1[i] << endl;
    }

    cout << endl << "Subtracting 3rd element from a1 which is "<< a1[3] << endl << endl;
    a1.erase(a1.cbegin()+3);
    
    for (int i = 0; i < a1.size(); i++)
    {
        cout << i << " element is " << a1[i] << endl;
    }

    cout <<"\n\nFinding the "<<*find(a1.begin(), a1.end(), 1) << " in A1 array using find method\n\n";

    
    cout << "\n\nA2 array's size is " << a2.size() << endl;
    cout << "Setting a2 array equal to a1\n";
    a2 = a1;
    cout << endl;
    cout << "Printing with for_each method\n";
    cout << "Elements Are   \n";
    for_each(a2.begin(),a2.end(),print<int>);
    

    a2.clear();
    a3 = a2;
    cout << endl;
    cout << "A2 array's elements    \n";
    cout << "Printing with iterator increment method \n";
    for (auto i = a3.begin(); i != a3.end(); i++)
    {
        cout << j << " element is " << *i << endl;
        j++;
    }

    cout << "A4 array is \n";
    for (int i = 0; i < a4.size(); i++)
    {
        cout << i << " element is " << a4[i] << endl;
    }
    cout << "\n\nFilling A4 array with number 3\n";
    cout << endl;
    a4.fill(3);
    j = 0;
    cout << "Printing with ranged based method \n";
    for (auto& i : a4)
    {
        cout  << j+1 << " element is " << i << endl;
        j++;
    }

    cout << endl;
    cout << endl;


                                            
                                            
    ////////////////////////////////// TESTING VECTORS ////////////////////////////////////////////
                                            cout << "\t\t\t\tVECTORS";
    GTUVector<int> v1(5), v2 , v3(4) , v4(5);
    
    cout << "V1 vector is empty and it's Size is " << v1.size() << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << i << " element is " << v1[i] << endl;
    }

    cout << "\n\nAdding 3,2,1,7,4 to v1 vector\n";
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(7);
    v1.push_back(4);
    
    cout << "V1 vector's elements    \n\n";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << i << " element is " << v1[i] << endl;
    }

    cout << endl << "Subtracting 3rd element from v1 which is "<< v1[3] << endl << endl;
    v1.erase(v1.cbegin()+3);
    
    for (int i = 0; i < v1.size(); i++)
    {
        cout << i << " element is " << v1[i] << endl;
    }

    cout <<"\n\nFinding the "<<*find(v1.begin(), v1.end(), 1) << " in v1 vector using find method\n\n";

    
    cout << "\n\nv2 vector's size is " << v2.size() << endl;
    cout << "Setting a2 vector equal to a1\n";
    v2 = v1;
    cout << endl;
    cout << "Printing with for_each method\n";
    cout << "Elements Are   \n";
    for_each(v2.begin(),v2.end(),print<int>);
    

    v2.clear();
    v3 = v2;
    cout << endl;
    cout << "v2 vector's elements    \n";
    cout << "Printing with iterator increment method \n";
    for (auto i = v3.begin(); i != v3.end(); i++)
    {
        cout << j << " element is " << *i << endl;
        j++;
    }

    cout << "v4 vector is \n";
    for (int i = 0; i < v4.size(); i++)
    {
        cout << i << " element is " << v4[i] << endl;
    }
    cout << "\n\nRemoving last element " << v1.back() << " from v1 vector\n";
    cout << endl;
    v1.pop_back();
    j = 0;
    cout << "Printing with ranged based method \n";
    for (auto& i : v1)
    {
        cout  << j+1 << " element is " << i << endl;
        j++;
    }

    cout << endl;
    cout << endl;


    ////////////////////////////////// TESTING SETS ////////////////////////////////////////////
                                cout << "\t\t\t\tSETS\n";
    GTUSet<int> s1(5), s2 , s3(4) , s4(6);

    cout << "Adding 3 2 1 9 0 8 to s2 Set using add Method\n";
    s2.add(3);
    s2.add(2);
    s2.add(1);
    s2.add(3);
    s2.add(9);
    s2.add(0);
    s2.add(8);
    cout << "\nPrinting The s2 set using iterator increment method\n";
    j= 0;
    for (auto i = s2.begin();  i != s2.end(); i++, j++)
    {
        cout << j+1 << "th element is " << *i << endl;
    }

    s2.add(9);
    s2.add(9);
    s2.add(9);
    s2.add(9);
    cout << "\nAddin 9 multiple times\n";
    cout << "\nPrinting The s2 set using range based for loop method\n";
    j= 0;
    for (auto& i : s2)
    {
        cout << j+1 << "th element is " << i << endl;
        j++;
    }
    
    s2.deleteElm(9);
    cout << "\nRemoving 9 from the s2 set\n";
    cout << "\nPrinting The s2 set using for_each method\n";
    j= 0;
    for_each(s2.begin(),s2.end(),print<int>);
    
    
    

    cout << "Adding 2 1 3 5 8 7 to s3 Set using add Method\n";
    s3.add(2);
    s3.add(1);
    s3.add(3);
    s3.add(5);
    s3.add(8);
    s3.add(7);
    cout << "\nPrinting The s2 set using size increment method\n";
    j= 0;
    for (int i = 0;  i < s3.size(); i++, j++)
    {
        cout << j+1 << "th element is " << s3[i] << endl;
    }


    cout << "\n\nIntersection  of S2 and S3 sets\n";
    j= 0;
    GTUSet<int> SetIn(s2.intersection(s3));
    for (int i = 0;  i < SetIn.size(); i++)
    {
        cout << i+1 << "th element is " << SetIn[i] << endl;
    }

    
    cout << "\n\nGOODBYE :)\n\n";

    return 0;
}