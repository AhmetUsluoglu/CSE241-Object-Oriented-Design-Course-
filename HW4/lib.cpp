#include "lib.h"

namespace sets{
/*Day Of Year Set Functions*/
int DayOfYearSet :: total = 0;

    /*Constructors*/

DayOfYearSet::DayOfYearSet(/* args */){
    DayOfYear date;
    add(date);
}
DayOfYearSet::DayOfYearSet(int monthValue, int dayValue){
    DayOfYear date(monthValue, dayValue);
    add(date);
}
DayOfYearSet::DayOfYearSet(DayOfYear date)  {add(date);}
DayOfYearSet::DayOfYearSet(vector<DayOfYear> dates){
    for (int i = 0; i < dates.size(); i++) add(dates[i]);
}

DayOfYearSet::~DayOfYearSet()
{}

    /*Set Modification Functions*/
int DayOfYearSet::Size(){return size;};

/*Adds a new member to the set*/
int DayOfYearSet :: add(DayOfYear date)
{
    this->add(date.getMonth(),date.getDay());
    return 0;
}
/*Adds a new member to the set*/
int DayOfYearSet :: add(int monthValue, int dayValue)
{
    if(testDate(monthValue, dayValue) == 1) return 0;
    for (int i = 0; i < size; i++)
    {
        if(monthValue == set[i].getMonth() && dayValue == set[i].getDay()) return 0;
    }
    DayOfYearSet :: DayOfYear *temp;
    temp = set;
    set = new DayOfYear[size + 1];
    for (int i = 0; i < size; i++)   set[i].setdate(temp[i].getMonth(),temp[i].getDay());
    set[size] = DayOfYearSet::DayOfYear(monthValue, dayValue);
    size++;
    total++;
    return 0;
}

/*Checks the validity of the member date*/
int DayOfYearSet :: testDate(int monthValue, int dayValue)
{
    int exit = 0;
    int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((monthValue < 1) || (monthValue > 12))
    {
        exit = 1;
    }
    else 
    {
        if((arr[monthValue] < dayValue || dayValue < 1))
        {
            exit = 1;
        }
    }
    return exit;
}

/*Removes an element from the set at given position*/
int DayOfYearSet ::remove(int index)
{
    for (int i = index; i <= size; i++)
    {
        set[i] = set[i+1];
    }
    set[size].setdate(0,0);  
    size--;
    total--;
    return 0;
}

    /*Operator Overloading Functions*/

/*If 2 sets are equal returns true*/    
bool DayOfYearSet ::operator == (DayOfYearSet set1)
{
    int flag = 0;
    if(this->size == set1.size)
    {
        for (auto i = 0; i < size; i++)
        {
            flag = 0;
            for (decltype(i) j = 0; j < size; j++)
            {
                if(this->set[i].getDay() == set1.set[j].getDay() && this->set[i].getMonth() == set1.set[j].getMonth())
                {flag = 1;}
            }
        }
    }
    return flag;
}

/*If 2 sets are equal returns false*/    
bool DayOfYearSet :: operator != (DayOfYearSet set1){return !(this->operator==(set1));}

/*Assigns right set to left set*/
DayOfYearSet& DayOfYearSet:: operator = (DayOfYearSet set1)
{   
    size = set1.size; 
    set = new DayOfYear[size];
    for (int i = 0; i < size; i++)   set[i].setdate(set1[i].getMonth(),set1[i].getDay());
    return *this;
}

/*Reaches an element at the given position*/
DayOfYearSet::DayOfYear&  DayOfYearSet::operator[](int index){return set[index];}

/*returns  the intersection set of two sets*/
DayOfYearSet DayOfYearSet::operator ^ (DayOfYearSet set1)
{
    vector<DayOfYear> unionMem;
    for (auto i = 0; i < this->size; i++)
    {
        for (decltype(i) j = 0; j < set1.size; j++)
        {
            if(this->set[i].getDay() == set1.set[j].getDay() && this->set[i].getMonth() == set1.set[j].getMonth())
            {unionMem.push_back(set1.set[j]);}
        }
    }
    DayOfYearSet unionSet(unionMem);
    return unionSet;
}

/*returns the elements exclusive of right set as a set*/
DayOfYearSet DayOfYearSet::operator - (DayOfYearSet set1)
{
    int flag = 0;
    vector<DayOfYear> unionMem;
    for (auto i = 0; i < this->size; i++)
    {
        flag = 0;
        for (decltype(i) j = 0; j < set1.size; j++)
        {
            if(this->set[i].getDay() == set1.set[j].getDay() && this->set[i].getMonth() == set1.set[j].getMonth())
            {flag = 1;}
        }
        if(flag == 0) unionMem.push_back(set[i]);
    }
    DayOfYearSet unionSet(unionMem);
    return unionSet;
}

/*returns  the union set of two sets*/
DayOfYearSet DayOfYearSet::operator + (DayOfYearSet set1)
{
    int flag = 0;
    DayOfYearSet unionSet = *this;

    for (auto i = 0; i < set1.size; i++)
    {
        flag = 0;
        for (decltype(i) j = 0; j < this->size; j++)
        {
            if(this->set[i].getDay() == set1.set[j].getDay() && this->set[i].getMonth() == set1.set[j].getMonth())
            {flag = 1;}
        }
        if(flag == 0) unionSet.add(set1[i]);
    }
    
    return unionSet;
   
}

/*Returns the set of elements that is not in the given set*/
DayOfYearSet DayOfYearSet:: operator!(void) const
{
    DayOfYearSet complement;
    int flag = 0;
    complement.remove(0);
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= 31; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if((this->set[k].getMonth() == i && this->set[k].getDay() == j))
                {   
                    k = size;
                    flag = 1;
                }
            }
            if(flag == 0) complement.add(i,j);
            flag = 0;
        }
    }
    return complement;
}



/*Day Of Year Functions*/

    /* Constructors*/

DayOfYearSet::DayOfYear::DayOfYear(int monthValue, int dayValue) 
                          : month(monthValue), day(dayValue)
{
     if(testDate()) month = 1, day = 1;
}

DayOfYearSet::DayOfYear::DayOfYear(int monthValue) : month(monthValue), day(1)
{
    if(testDate()) month = 1;
}

DayOfYearSet::DayOfYear::DayOfYear( ) : month(1), day(1) 
{}

/*Checks the validity of the dates*/
int DayOfYearSet :: DayOfYear :: testDate( ){
    int exit = 0;
    int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((month < 1) || (month > 12))
    {
        exit = 1;
    }
    else 
    {
        if((arr[month] < day || day < 0))
        {
            exit = 1;
        }
    }
    return exit;
}

int DayOfYearSet::DayOfYear::getMonth( ){return month;}

int DayOfYearSet::DayOfYear::getDay( ){return day;}

void DayOfYearSet :: DayOfYear :: setdate(int monthValue, int dayValue) { month = monthValue, day = dayValue;}

/*Stream insertion operator overloaded as printing all info about the given set*/
ostream & operator << (ostream &out, const DayOfYearSet &c)
{
    out << "\nSize of This Set is = " << c.size << endl;
    for (int i = 0; i < c.size; i++)
    {
        out <<"("<<c.set[i].getMonth() << "," << c.set[i].getDay()<<")";
    }
    out << endl<< endl<< endl;
    return out;
}

}