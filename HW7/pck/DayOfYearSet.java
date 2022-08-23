package pck;
import java.util.ArrayList;

/**
 * DayOfYearSet class contains set of DayOfYear objects for every element of the set that corresponds to the single day of a year
 */
public  class DayOfYearSet
{
    /**
     * DayOfYear class contains information for a day of a year.
     */
    public static class DayOfYear
    {
        /**
         * Initializes the month and day to arguments.
         * @param monthValue    month value of the date
         * @param dayValue      day value of the date
         */
        public DayOfYear(int monthValue, int dayValue)
        {
            month = monthValue;
            day = dayValue;

            if(testDate())
            {
                month = 1;
                day = 1;
            }
        }
            
        
        /**
         * Initializes the date to the first of the given month.
         * @param monthValue month value
         */
        public DayOfYear(int monthValue)
        {
            month = monthValue;
            day = 1;
            if(testDate())
            {
                month = 1;
                day = 1;
            }
        }
            
        /**
         * No Parameter DayOfYear constructor sets the date to 1 January
         */
        public DayOfYear( )
        {
            day = 1;
            month = 1;
        }
        
        /**
         * Getter function for month filed
         * @return returns month
         */        
        public int getMonth( ){return month;}
            //Returns 1 for January, 2 for February, etc.
        
        /**
         * Getter function for day filed
         * @return returns day
         */    
        public int getDay( ){return day;}

        
        /**
         * Tests the given date's vallidity
         * @return true if it's not valid
         */
        public boolean testDate( )
        {
            boolean exit = false;
            int arr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            if ((month < 1) || (month > 12))
            {
                exit = true;
            }
            else 
            {
                if((arr[month] < day || day < 0))
                {
                    exit = true;
                }
            }
            return exit;
        }

        private int month;
        private int day;
    }

    /**
     * Function returns a static integer value equals to all alive objects in all classes
     * @return  returns total
     */
    public static int getTotal(){return total;}
    
    /**
     * No Argument Constructor Does Nothing
     */
    public DayOfYearSet(/* args */)
    {/*Body Intentionally Empty*/}
    
    /**
     * Two integer parameter constructor adds an elemnent to the set
     * @param monthValue    month value of the date
     * @param dayValue      day value of the date
     */
    public DayOfYearSet(int monthValue, int dayValue)
    {
        DayOfYear date = new DayOfYear(monthValue, dayValue);
        add(date);
    }
    /**
     * DatOfYear parameter constructor adds an elemnent to the set
     * @param date contains date information
     */
    public DayOfYearSet(DayOfYear date)
    {
        add(date);
    }
    /**
     * ArrayList of DayOfYeat Objects parameter constructor adds an list of DayOfYear objects to the set
     * @param dates list of DayOfYear Objects that will be added to the set
     */
    public DayOfYearSet(ArrayList <DayOfYear> dates)
    {
        for (int i = 0; i < dates.size(); i++) add(dates.get(i));
    }


    /**
     * Getter functino for size field
     * @return  returns  the size of the set
     */
    public int size(){return size;}
    
    /**
     * Adds an element to the set if it's not already added.
     * @param date contains date information of the item that will be added to the set
     */
    public void add(DayOfYear date)
    {
        if(testDate(date.getMonth(),date.getDay())) {return;}
        set[size] = date;
        size++;
        totalplus();
    }
    
    /**
     * Adds an element to the set if it's not already added.
     * @param monthValue    month value of the date
     * @param dayValue      day value of the date
     */
    public void add(int monthValue, int dayValue)
    {
        if(testDate(monthValue,dayValue)) {return;}
        for (int i = 0; i < size; i++)
        {
            if(monthValue == set[i].getMonth() && dayValue == set[i].getDay()) return;
        }
        DayOfYear temp = new DayOfYear(monthValue,dayValue);
        add(temp);
    }

    /**
     * Removes the last element from the set
     */
    public void remove()
    {
        if(1 > size) return;
        set[size-1] = null;  
        size--;
        totalminus();
    }
    
    /**
     * Removes an element from the set
     * @param date contains date information
     */
    public void remove(DayOfYear date)
    {
        remove(date.month,date.day);
    }

    /**
     * Removes an element from the set
     * @param monthValue    month value of the date
     * @param dayValue      day value of the date
     */
    public void remove(int monthValue, int dayValue)
    {
        if(1 > size) return;
        int flag = 0;
        size--;
        for(int i = 0; i < size; i++)
        {
            if(monthValue == set[i].month && dayValue == set[i].day)
            {
                flag = 1;
            }
            if(flag == 1)
            {
                set[i] = set[i+1];
            }
        }
        set[size] = null;  
        totalminus();
    }

    /**
     * Test the given date's validity
     * @param monthValue    month value of the date
     * @param dayValue      day value of the date
     * @return      returns true if date is not valid
     */
    public boolean testDate(int monthValue, int dayValue)
    {
        boolean exit = false;
        int arr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if ((monthValue < 1) || (monthValue > 12))
        {
            exit = true;
        }
        else 
        {
            if((arr[monthValue] < dayValue || dayValue < 0))
            {
                exit = true;
            }
        }
        return exit;
    }
    
    /**
     * Static function increases static variable for counting alive objects in all classes
     */
    public static void totalplus(){total++;}
    /**
     * Static function decreases static variable for counting alive objects in all classes
     */
    public static void totalminus(){total--;}
    
    /**
     * Overriden equals function compares Sets correctly
     */
    @Override
    public boolean equals (Object set1)
    {
        if (set1 == this) return true;
        if (!(set1 instanceof DayOfYearSet)) return false;

        DayOfYearSet temp = (DayOfYearSet) set1;

        boolean flag = false;
        if(size == temp.size)
        {
            for (var i = 0; i < size; i++)
            {
                flag = false;
                for (var j = 0; j < size; j++)
                {
                    if(set[i].getDay() == temp.set[j].getDay() && set[i].getMonth() == temp.set[j].getMonth())
                    {flag = true;}
                }
            }
        }
        return flag;
    }
    
    /**
     * Overriden toString function prints Set details correctly
     */
    @Override
    public String toString() {

        String temp = "\n";
        int j = 0;
        for(var i = 0 ;i < size ; i++)
        {
            temp = temp + ( "(" + set[i].getMonth() +"."+ set[i].getDay() + ")  ");
            if(set[i].getMonth() < 10)
            {
                if(set[i].getDay() < 10)
                {
                    temp += "   ";
                }
                else temp += "  ";
            }
            else
            {
                if(set[i].getDay() < 10)
                {
                    temp += "  ";
                }
                else temp += " ";
            }
            if(i >= j+10)
            {
                j = i+1;
                temp += "\n";
            }
        }
        temp += "\n";

        temp += "Number of Elements in this set is " + size + "\n\n";
        return  temp;
    }

    /**
     * Creates a union set of the current set
     * @param set1  The set that will be added to union set
     * @return  returns reference to union set
     */
    public DayOfYearSet union(DayOfYearSet set1)
    {
        DayOfYearSet temp = new DayOfYearSet();
        temp.clone(this);
        temp.clone(set1);
        return temp;
    }

    /**
     * Creates an intersection set of the current set
     * @param set1  Set that the comparison will be done according to current set 
     * @return  returns reference to intersection set
     */
    public DayOfYearSet intersection (DayOfYearSet set1)
    {
        DayOfYearSet temp = new DayOfYearSet();

        for(var i = 0; i < size; i++)
        {
            for(var j = 0; j < set1.size; j++)
            {
                if(set[i].day == set1.set[j].day && set[i].month == set1.set[j].month)
                {
                    temp.add(set1.set[j].month,set1.set[j].day);
                }
            }
        }

        return temp;
    }

    /**
     * Creates a difference set of the current set
     * @param set1 Set that the comparison will be done according to current set 
     * @return  returns reference to difference set
     */
    public DayOfYearSet difference (DayOfYearSet set1)
    {
        DayOfYearSet temp = new DayOfYearSet();
        int flag = 1;
        for(var i = 0; i < size; i++)
        {
            flag = 0;
            for(var j = 0; j < set1.size; j++)
            {
                if(set[i].day == set1.set[j].day && set[i].month == set1.set[j].month)
                {
                    flag = 1;
                }
            }
            if(flag == 0) temp.add(set[i].month,set[i].day);
        }

        return temp;
    }

    /**
     * Creates a compelement set of the current set
     * @return refference to compelement set
     */
    public DayOfYearSet complement()
    {
        DayOfYearSet temp = new DayOfYearSet();
        for (int i = 1; i <= 12; i++)
        {
            for (int j = 1; j <= 31; j++)
            {
                temp.add(i,j);
                totalminus();
            }
        }
        return temp.difference(this);
    }

    /**
     * 
     * @param right is a DayOfYearSet object that will be copied
     * @return  reference to this object
     */
    public DayOfYearSet clone(DayOfYearSet right)
    {
        for(var i = 0; i < right.size; i++)
        {
            this.add(right.set[i].month,right.set[i].day);
            totalminus();
        }
        return this;
    }

    /* data */
    private int size = 0;   
    private DayOfYear[] set = new DayOfYear[365];
    private static int total;
    
    
}    