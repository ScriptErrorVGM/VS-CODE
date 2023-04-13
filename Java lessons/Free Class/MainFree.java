
import java.util.*;
public class MainFree {

    public static void main(String[] args) {

        Vehicle p1 = new Vehicle("Volvo", 1970);
        Vehicle p2 = new Vehicle("Porshe", 2019);
        System.out.println(p1.compareTo(p2));
        
        LinkedList<Vehicle> list = new LinkedList<>();
        list.addLast(new Vehicle("Toyota", 2012));
        list.addLast(new Vehicle("Mazda", 2016));
        list.addLast(new Vehicle("Dodge", 2005));
        list.addLast(new Vehicle("Jeep", 1980));
        list.addLast(new Vehicle("Range Rover", 2015));
        
        TreeSet<Vehicle> set = Vehicle.toTreeSet(list, p2);
        
        for(Vehicle p: set)
        {
            System.out.println(p);
        }
        
    }

}
