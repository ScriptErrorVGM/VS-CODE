public class App {
    public static void main(String[] args) throws Exception {
        Vector3D[] vectors = Vector3D.generate(10);
        Vector3D vectorA = new Vector3D(10, 50, -30);
        Vector3D vectorB = new Vector3D(60, -10, 35);
        
        System.out.format("A vector's axis is %s.\n", vectorA);
        System.out.format("B vector's axis is %s.\n", vectorB);
        System.out.format("A vector's length is %s.\n", vectorA.getModule());
        System.out.format("B vector's length is %s.\n", vectorB.getModule());
        System.out.format("The sum of these vectors is %s.\n", vectorA.getAddition(vectorB));
        System.out.format("The subtraction of these vectors is %s.\n", vectorA.getSubtraction(vectorB));
        System.out.format("The scalar product of these vectors is %s.\n", vectorA.getScalar(vectorB));
        System.out.format("The vector product of these vectors is %s.\n", vectorA.getVector(vectorB));

        System.out.format("0 vector's axis is %s.\n", vectors[0]);
        System.out.format("1 vector's axis is %s.\n", vectors[1]);
    }
}
