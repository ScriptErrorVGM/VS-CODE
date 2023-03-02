public class Vector3D {
    private double x, y, z;

    public Vector3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Vector3D() {
    }

    public double getModule() {
        return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2) + Math.pow(z, 2));
    }

    public Vector3D getAddition(Vector3D vector) {
        return new Vector3D(x + vector.x, y + vector.y, z + vector.z);
    }

    public Vector3D getSubtraction(Vector3D vector) {
        return new Vector3D(x - vector.x, y - vector.y, z - vector.z);
    }

    public double getScalar(Vector3D vector) {
        return x * vector.x + y * vector.y + z * vector.z;
    }

    public Vector3D getVector(Vector3D vector) {
        return new Vector3D(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
    }

    public static Vector3D[] generate(int n) {
        Vector3D[] vectors = new Vector3D[n];
        for(int i=0; i < n; i++){
            vectors[i] = new Vector3D(Math.random()*10, Math.random()*100, Math.random()*10);
        }
        return vectors;
    }

    @Override
    public String toString() {
        return "{" + x + "; " + y + "; " + z + "}";
    }

}