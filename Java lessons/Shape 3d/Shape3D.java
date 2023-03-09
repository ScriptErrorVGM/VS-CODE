import java.util.ArrayList;

class Shape {
    private double volume;

    public Shape(double volume) {
        this.volume = volume;
    }

    public double getVolume() {
        return volume;
    }

    @Override
    public String toString(){
        return "Volume {" + volume + " }";
    }
}

class SolidOfRevolution extends Shape {
    private double radius;

    public SolidOfRevolution(double volume, double radius) {
        super(volume);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

}

class Ball extends SolidOfRevolution {
    public Ball(double radius) {
        super(Math.PI * Math.pow(radius, 3) * 4 / 3, radius);
    }

    
}

class Cylinder extends SolidOfRevolution {
    private double height;

    public Cylinder(double radius, double height) {
        super(Math.PI * radius * radius * height, radius);
        this.height = height;
    }
}

class Pyramid extends Shape {
    private double h;
    private double s;

    public Pyramid(double h, double s) {
        super(h * s * 4 / 3);
        this.h = h;
        this.s = s;
    }

}

class Box extends Shape {
    private ArrayList<Shape> shapes = new ArrayList<>();
    private double free;

    public Box(double free) {
        super(free);
        this.free = free;
    }

    public boolean add(Shape shape) {
        if (free >= shape.getVolume()) {
            shapes.add(shape);
            free -= shape.getVolume();
            return true;
        } else {
            return false;
        }
    }
}





