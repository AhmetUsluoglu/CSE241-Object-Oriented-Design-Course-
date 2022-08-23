#include "lib.h"

using namespace sets;

/*Test all functions*/
int test(DayOfYearSet set1, DayOfYearSet& set2, DayOfYearSet set3, DayOfYearSet& set4, DayOfYearSet::DayOfYear date2)
{
    cout << "Constructor Control\n";
    cout << "Set1\n"<< set1 << "Set2\n"<< set2 << "Set3\n"<< set3 << "Set4\n"<< set4 <<endl;
    
    set1.add(date2);
    cout << "Adding date2 '(9,9)' to Set1 -->  " << set1 ;
    
    set1.add(10,10);
    cout << "Adding (10,10) to Set1 -->  " << set1 << endl;

    cout << "Second element of set4 is 1,1 --> " << set4[1].getMonth()<<","<<set4[1].getDay() << endl;
    cout << "Fourth element of set4 is 1,1 --> " << set4[3].getMonth()<<","<<set4[3].getDay() << endl;


    cout << "Set1 is equal Set2 = false --> " << (set1 == set2) << endl;
    cout << "Set1 is not equal Set2 = true--> " << (set1 != set2)<< endl;

    cout << "Set1 is equal Set3 = false --> " << (set1 == set3) << endl;
    cout << "Set1 is not equal Set3 = true--> " << (set1 != set3)<< endl;

    set1 = set2;
    cout << "Set1" << set1 << "Set2" << set2;
    cout << "Set1 is equal Set2 = True --> " << (set1 == set2) << endl;

    cout << "Set2  " << set2 << "Set3  " << set3;
    cout << "set2 + set3" << (set2+set3);
    cout << "set2 - set3" << (set2-set3);
    cout << "set2 ^ set3" << (set2^set3);


    cout << "removing 2,2 from set4 --> " << set4.remove(1) << set4;
    cout << "removing 5,5 from set4 --> " << set4.remove(3) << set4;

    cout << "Compelement of Set2 --> " << !set2;

    cout << "Total Day Count :"<< DayOfYearSet :: getTotal()<< endl << endl;

    cout <<"Set1 " << set1 <<"Set2 " << set2 <<"Set3 " << set3 <<"Set4 " << set4;

    cout <<"\n(!(set1 + set2) == (!set1 ^ !set2) is true -->  " << ((!(set1 + set2)) == (!set1 ^ !set2));
    cout <<"\n(set1 + set2) = " <<(set1 + set2);
    cout << "(!(set1 + set2)) = " << (!(set1 + set2)) << "((!set1) ^ (!set2)) = " << ((!set1) ^ (!set2));

    cout <<"\n(!(set1 + set3) == (!set1 ^ !set3) is true -->  " << ((!(set1 + set3)) == ((!set1) ^ (!set3)));
    cout <<"\n(set1 + set3) = " <<(set1 + set3);
    cout << "(!(set1 + set3)) = "<< (!(set1 + set3)) << "((!set1) ^ (!set3)) = "<< ((!set1) ^ (!set3));

    cout <<"\n(!(set1 + set4) == (!set1 ^ !set4) is true -->  " << (!(set1 + set4) == (!set1 ^ !set4));
    cout <<"\n(set1 + set4) = " <<(set1 + set4);
    cout << "(!(set1 + set4)) = " << (!(set1 + set4)) << "((!set1) ^ (!set4)) = " << ((!set1) ^ (!set4));

    cout <<"\n(!(set3 + set2) == (!set3 ^ !set2) is true -->  " << (!(set3 + set2) == (!set3 ^ !set2));
    cout <<"\n(set2 + set3) = " <<(set3 + set2);
    cout << "(!(set2 + set3)) = " << (!(set2 + set3)) << "((!set3) ^ (!set2)) = " << ((!set3) ^ (!set2));
    
    cout <<"\n(!(set4 + set2) == (!set4 ^ !set2) is true -->  " << (!(set4 + set2) == (!set4 ^ !set2));
    cout <<"\n(set4 + set2) = " <<(set2 + set4);
    cout << "(!(set4 + set2)) = " <<(!(set4 + set2)) << "((!set4) ^ (!set2)) = " << ((!set4) ^ (!set2));

    fstream my_file;
    my_file.open("set1.txt", ios::out);
    if (!my_file)   cerr << "File is not created\n";
    else my_file << set1;
    cout << "Set1 is written to the set1.txt file\n";

    fstream my_file1;
    my_file1.open("set4.txt", ios::out);
    if (!my_file1)   cerr << "File is not created\n";
    else my_file1 << set4;
    cout << "Set4 is written to the set4.txt file\n";

    return 0;
}

int main()
{
    vector<DayOfYearSet::DayOfYear> elements {{1,1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}};
    DayOfYearSet::DayOfYear date1;
    DayOfYearSet::DayOfYear date2(9,9);
    DayOfYearSet::DayOfYear date3(10,10);
    DayOfYearSet set1;
    DayOfYearSet set2(2,15);
    DayOfYearSet set3(date2);
    DayOfYearSet set4(elements);
    
    /*Test function takes its elements by value and by refference*/
    test(set1, set2, set3, set4, date2);

    
    return 0;
}