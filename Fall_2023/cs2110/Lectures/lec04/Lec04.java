public class Lec04 {
    /**
     * Return a solution `x` to the equation `a*x^2 + b*x + c = 0`.  Requires `a != 0`,
     * `b^2 >= 4*a*c`.
     */
    public static double qSolve(double a, double b, double c) {
        // Quadratic formula for the larger (in magnitude) of the roots.
        return (-b - Math.copySign(Math.sqrt(b * b - 4 * a * c), b)) / (2 * a);
    }

}
