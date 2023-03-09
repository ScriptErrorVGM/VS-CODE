public class Main {

    public static void main(String[] args) {
        Ball ball = new Ball(4.5);
        Cylinder cylinder = new Cylinder(4, 4);
        Pyramid pyramid = new Pyramid(20, 20);

        Box box = new Box(1000);

        System.out.println(box.add(ball)); 
        System.out.println(box.add(cylinder)); 
        System.out.println(box.add(pyramid));

        System.out.println(ball);
        System.out.println(pyramid);
        System.out.println(cylinder);         
    }
}