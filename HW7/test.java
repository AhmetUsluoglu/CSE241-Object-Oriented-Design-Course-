import pck.DayOfYearSet;
import java.util.ArrayList;

/**
 * Tests the functions and classes in the program.
 */
class test{  
    
    public static void main(String[] args)
    {
        ArrayList<DayOfYearSet.DayOfYear> list1 = new ArrayList<>();
        list1.add(new DayOfYearSet.DayOfYear(3,2));
        list1.add(new DayOfYearSet.DayOfYear(11,12));
        list1.add(new DayOfYearSet.DayOfYear(10,21));

        ArrayList<DayOfYearSet.DayOfYear> list2 = new ArrayList<>();
        list2.add(new DayOfYearSet.DayOfYear(3,2));
        list2.add(new DayOfYearSet.DayOfYear(11,12));
        list2.add(new DayOfYearSet.DayOfYear(5,2));
        list2.add(new DayOfYearSet.DayOfYear(5,5));
        list2.add(new DayOfYearSet.DayOfYear(5,6));
        list2.add(new DayOfYearSet.DayOfYear(6,3));
        list2.add(new DayOfYearSet.DayOfYear(5,1));

        //Testing 3 DayOfYear Constructors
        DayOfYearSet.DayOfYear date1 = new DayOfYearSet.DayOfYear();
        DayOfYearSet.DayOfYear date2 = new DayOfYearSet.DayOfYear(3);
        DayOfYearSet.DayOfYear date3 = new DayOfYearSet.DayOfYear(3,2);

        DayOfYearSet.DayOfYear date4 = new DayOfYearSet.DayOfYear();
        DayOfYearSet.DayOfYear date5 = new DayOfYearSet.DayOfYear(5);
        DayOfYearSet.DayOfYear date6 = new DayOfYearSet.DayOfYear(6,3);

        //Testing 4 DayOfYearSet Constructors
        DayOfYearSet set1 = new DayOfYearSet();
        DayOfYearSet set2 = new DayOfYearSet(6,3);
        DayOfYearSet set3 = new DayOfYearSet(date3);
        DayOfYearSet set4 = new DayOfYearSet(list1);
        
        DayOfYearSet set5 = new DayOfYearSet();
        DayOfYearSet set6 = new DayOfYearSet(8,2);
        DayOfYearSet set7 = new DayOfYearSet(date6);
        DayOfYearSet set8 = new DayOfYearSet(list2);


        
        
        System.out.print("Total Elements Alive is " + DayOfYearSet.getTotal() + "\n\n"); 
        
        System.out.print("\n\t== Printing Set 1 ==" + set1.toString()); 
        System.out.print("\n\t== Printing Set 2 ==" + set2.toString()); 
        System.out.print("\n\t== Printing Set 3 ==" + set3.toString());
        System.out.print("\n\t== Printing Set 4 ==" + set4.toString());
        System.out.print("\n\t== Printing Set 5 ==" + set5.toString()); 
        System.out.print("\n\t== Printing Set 6 ==" + set6.toString()); 
        System.out.print("\n\t== Printing Set 7 ==" + set7.toString());
        System.out.print("\n\t== Printing Set 8 ==" + set8.toString());
        

        set2.add(4,2);
        set2.add(5,2);
        System.out.print("\n\n\n\t== Adding 4.2 and 5.2 to Set 2 ==" + set2.toString());
        System.out.print("Total Elements Alive is " + DayOfYearSet.getTotal() + "\n\n"); 

        set2.remove();
        System.out.print("\n\t== Removing last element from Set 2 ==" + set2.toString());
        System.out.print("Total Elements Alive is " + DayOfYearSet.getTotal() + "\n\n"); 

        set2.remove(date6);
        System.out.print("\n\t== Removing date6 (6.3) from Set 2 ==" + set2.toString());
        System.out.print("Total Elements Alive is " + DayOfYearSet.getTotal() + "\n\n"); 

        set2.remove(5,2);
        set2.add(6,3);
        System.out.print("\n\t== Removing 5.2 from Set 2 and adding 6.3 ==" + set2.toString());
        System.out.print("Total Elements Alive is " + DayOfYearSet.getTotal() + "\n\n"); 

        System.out.print("\n\n\n\tIs Set2 and Set3 equal? " + set2.equals(set3) + "\n");
        System.out.print("\n\t== Printing Set 2 ==" + set2.toString()); 
        System.out.print("\n\t== Printing Set 3 ==" + set3.toString());
        System.out.print("\n\n\tIs Set2 and Set7 equal? " + set2.equals(set7) + "\n");
        System.out.print("\n\t== Printing Set 2 ==" + set2.toString()); 
        System.out.print("\n\t== Printing Set 7 ==" + set7.toString());


        System.out.print("\n\n\n\tUnion of Set2 and Set3 is " + set2.union(set3));
        System.out.print("\tUnion of Set2 and Set8 is " + set2.union(set8));


        System.out.print("\n\n\n\tIntersection of Set3 and Set4 is " + set3.intersection(set4));
        System.out.print("\tIntersection of Set4 and Set8 is " + set4.intersection(set8));


        System.out.print("\n\n\n\tDifference of Set4 and Set8 is " + set4.difference(set8));
        System.out.print("\tDifference of Set8 and Set4 is " + set8.difference(set4));

        
        //!(s1 + s2) == !s1 ^ !s2
        System.out.print("\n\n!(Set2 + Set3)" + set2.union(set3).complement());
        System.out.print("\n\n!Set2 ^ !Set3" + set2.complement().intersection(set3.complement()));
        System.out.print("!(Set2 + Set3) == !Set2 ^ !Set3 ==> " + set2.union(set3).complement().equals(set2.complement().intersection(set3.complement())) + "\n\n");

        System.out.print("\n\n!(Set2 + Set4)" + set2.union(set4).complement());
        System.out.print("\n\n!Set2 ^ !Set4" + set2.complement().intersection(set4.complement()));
        System.out.print("!(Set2 + Set4) == !Set2 ^ !Set4 ==> " + set2.union(set4).complement().equals(set2.complement().intersection(set4.complement())) + "\n\n");

        System.out.print("\n\n!(Set8 + Set4)" + set8.union(set4).complement());
        System.out.print("\n\n!Set8 ^ !Set4" + set8.complement().intersection(set4.complement()));
        System.out.print("!(Set8 + Set4) == !Set8 ^ !Set4 ==> " + set8.union(set4).complement().equals(set8.complement().intersection(set4.complement())) + "\n\n");

        System.out.print("\n\n!(Set2 + Set6)" + set2.union(set6).complement());
        System.out.print("\n\n!Set2 ^ !Set6" + set2.complement().intersection(set6.complement()));
        System.out.print("!(Set2 + Set6) == !Set2 ^ !Set6 ==> " + set2.union(set6).complement().equals(set2.complement().intersection(set6.complement())) + "\n\n");

        System.out.print("\n\n!(Set3 + Set7)" + set3.union(set7).complement());
        System.out.print("\n\n!Set3 ^ !Set7" + set3.complement().intersection(set7.complement()));
        System.out.print("!(Set3 + Set7) == !Set3 ^ !Set7 ==> " + set3.union(set7).complement().equals(set3.complement().intersection(set7.complement())) + "\n\n");


        System.out.print("\n\n\tGOODBYE :)\n\n");
    }  
}  