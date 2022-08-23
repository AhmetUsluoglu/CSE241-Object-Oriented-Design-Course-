#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;
namespace sets{
class DayOfYearSet{
    
public:
    class DayOfYear
    {
        public:
            DayOfYear(int monthValue, int dayValue);
            //Initializes the month and day to arguments.
        
            DayOfYear(int monthValue);
            //Initializes the date to the first of the given month.
        
            DayOfYear( );
            //Initializes the date to January 1.
        
            //void input( );
            //void output( );
            int getMonth( );
            //Returns 1 for January, 2 for February, etc.

            int getDay( );

            void setdate(int monthValue, int dayValue);
            int testDate( );

        private:
            int month;
            int day;
    };
    /*Object counter function*/
    static int getTotal(){return total;};
    /*Constructors*/
    DayOfYearSet(/* args */);
    DayOfYearSet(int monthValue, int dayValue);
    DayOfYearSet(DayOfYear date);
    DayOfYearSet(vector<DayOfYear> dates);

    ~DayOfYearSet();

    /*Set modification funtions*/
    int Size();
    
    int add(DayOfYear date);
    int add(int monthValue, int dayValue);

    int remove(int index);
    int testDate(int monthValue, int dayValue);


    /*Opeartor overload functions*/
    DayOfYear& operator[](int index);
    bool operator == (DayOfYearSet set1);
    bool operator != (DayOfYearSet set1);
    DayOfYearSet& operator = (DayOfYearSet set1);
    DayOfYearSet operator ^ (DayOfYearSet set1);
    DayOfYearSet operator + (DayOfYearSet set1);
    DayOfYearSet operator - (DayOfYearSet set1);
    DayOfYearSet operator!(void) const;
    friend ostream & operator << (ostream &out, const DayOfYearSet &c);
    
private:
    /* data */
    int size = 0;
    DayOfYear* set;
    static int total;
};

ostream & operator << (ostream &out, const DayOfYearSet &c);

}