public class Demo {
    public static void main(String[] args) {
        Point p1 = new Point(3, -2);

        // Show off `toString()`
        System.out.println("p1 is at " + p1);
        // Equivalent to this:
        // System.out.println("p1 is at " + p1.toString());

        // Demonstrate reference vs. value equality
        Point p2 = new Point(3, -2);
        System.out.println("p1 == p2? " + (p1 == p2));
        System.out.println("p1.equals(p2)? " + p1.equals(p2));
    }
}
