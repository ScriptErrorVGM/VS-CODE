import java.util.*;

public class Vehicle implements Comparable {
    public String name;
    public int series;
    
    public Vehicle (String name, int series) 
    {
         this.name = name;
         this.series = series;
    }
    
    public int compareTo(Object o)
    {
        if (o instanceof Vehicle)
        {
            Vehicle p = (Vehicle)o;
            if (series > p.series) return 1;
            if (series == p.series) return 0;
            if (series < p.series) return -1;
        }       
        return -1;        
    }
    
    public String toString()
    {
        return name + " " + series;
    }
    
    public static TreeSet<Vehicle> toTreeSet(LinkedList<Vehicle> list, Vehicle p)
    {
        TreeSet<Vehicle> set = new TreeSet<>();
        
        for(Vehicle p1 : list)
        {
            set.add(p1);
        }
        
        return set;
    }
    
}
