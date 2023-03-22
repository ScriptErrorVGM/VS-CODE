public class Test {
    public static void main(String[] args) {
        myStack<Integer> mystack = new myStack<Integer>();

        mystack.add(1);
        mystack.add(2);

        mystack.remove(2);
        mystack.remove(1);

        mystack.add(3);
        mystack.add(4);
        
        System.out.println(mystack.numSmaller(4));
        System.out.println(mystack.numSmaller(3));

        System.out.println(mystack.isSame(3));
        System.out.println(mystack.isSame(2));
        
        System.out.println("My array list : " + mystack.toString());

    }
}
