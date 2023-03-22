import java.util.*;

public class myStack <T extends Comparable<T>> {
    private final int MAX = 10;
    private int size;
    private ArrayList<T> array;

    public myStack()  {
        size = 0;
        array = new ArrayList<>(MAX);
    }

    public void add(T i) {
        if (size < MAX) {
            array.add(i);
            size++;            
        }        
    }

    public void remove(T x) {
        if (size > 0) {
            array.remove(x);
            size--;            
        }        
    }

    public int numSmaller(T x) {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (x.compareTo(array.get(i)) > 0 ) {
                count++;
            }                   
        }
        return count;
    }

    public boolean isSame(T x) {
        for (int i = 0; i < size; i++)
        {
            if (x.compareTo(array.get(i)) == 0) {
                return true;
            }                   
        }
        return false;
    }

    @Override
    public String toString() {
        String result = "";
        for (int i = 0; i < size; i++)
        {
            result = result + array.get(i) + ", ";
            
        }
        return result;
    }


}
