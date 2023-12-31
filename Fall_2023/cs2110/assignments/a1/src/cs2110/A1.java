package cs2110;

import java.lang.Math;
/*
 * Assignment metadata
 * Name and NetID: TODO (TODO)
 * Hours spent on assignment: TODO
 */

/**
 * Collection of misc. static functions for showcasing the capabilities of Java in a procedural
 * context.
 */
public class A1 {

    public static void main(String[] args) {
        /* Compute the area of the polygon */
        double area = polygonArea(5,6);
        System.out.println("the calculated area is=" + area);

        /* Compute Collatz */
        int output = collatzSum(15);
        System.out.println("the sum of the collatz is=" + output);
    }

    /**
     * Return the area of a regular polygon with `nSides` sides of length `sideLength`. Units of
     * result are the square of the units of `sideLength`. Requires `nSides` is at least 3,
     * `sideLength` is non-negative.
     */
    public static double polygonArea(int nSides, double sideLength) {
        double A=(1.0/4.0)*Math.pow(sideLength,2)*(nSides/(Math.tan(Math.PI/nSides)));
        return A;
    }

    /**
     * Return the next term in the Collatz sequence after the argument.  If the argument is even,
     * the next term is it divided by 2.  If the argument is odd, the next term is 3 times it plus
     * 1.  Requires magnitude of odd `x` is less than `Integer.MAX_VALUE/3` (otherwise overflow is
     * possible).
     */
    public static int nextCollatz(int value){
        if(value % 2 == 0) {
            return value = value / 2;
        } else {
            return value = value * 3 + 1;
        }
    }

    /**
     * Return the sum of the Collatz sequence starting at `seed` and ending at 1 (inclusive).
     * Requires `seed` is positive, sum does not overflow.
     */
    public static int collatzSum(int seed) {
        // Implementation constraint: Use a while-loop.  Call `nextCollatz()` to
        // advance the sequence.
        int value = seed; // initial set value to seed
        int sum = 0;      // running sum of calculated values
        // loop until value .lt. 1
        while (value > 1)
        {
            value = nextCollatz(value); // advance value
            sum = sum + value;  // keep running total of integers
        }
        return sum;
    }

    /**
     * Return the median value among `{a, b, c}`.  The median has the property that at least half of
     * the elements are less than or equal to it and at least half of the elements are greater than
     * or equal to it.
     */
    public static int med3(int a, int b, int c) {
        // Implementation constraint: Do not call any other methods.
        int left,middle,right; //integers for sorting
        // TODO: Implement this method according to its specifications.
        throw new UnsupportedOperationException();
    }

    /**
     * Return whether the closed intervals `[lo1, hi1]` and `[lo2, hi2]` overlap.  Two intervals
     * overlap if there exists a number contained in both of them.  Notation: the interval `[lo,
     * hi]` contains all numbers greater than or equal to `lo` and less than or equal to `hi`.
     * Requires `lo1` is less than or equal to `hi1` and `lo2` is less than or equal to `hi2`.
     */
    public static boolean intervalsOverlap(int lo1, int hi1, int lo2, int hi2) {
        // Implementation constraint: Use a single return statement to return
        // the value of a Boolean expression; do not use an if-statement.

        // TODO: Implement this method according to its specifications.
        throw new UnsupportedOperationException();
    }

    /**
     * Return the approximation of pi computed from the sum of the first `nTerms` terms of the
     * Madhava-Leibniz series.  This formula states that pi/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
     * Requires `nTerms` is non-negative.
     */
    public static double estimatePi(double nTerms) {
        // Implementation constraint: Use a for-loop.  Do not call any other
        // methods (including `Math.pow()`).
        double sum = 0;      // running sum of calculated values

        for(double i=0; i<nTerms; i++) {
            if (i % 2 == 0) {
              sum += -1 / (2*i - 1); }
            else {
                sum += 1 / (2*i - 1); }
        }

        return sum;
    }

    /**
     * Returns whether the sequence of characters in `s` is equal (case-sensitive) to that sequence
     * in reverse order.
     */
    public static boolean isPalindrome(String s) {
        // Implementation constraint: Use the `charAt()` and `length()` methods
        // of the `String` class.

        // TODO: Implement this method according to its specifications.
        throw new UnsupportedOperationException();
    }

    /**
     * Return an order confirmation message in English containing the order ID and the number of
     * items it contains.  Message shall handle item plurality properly (e.g. "1 item" vs. "3
     * items") and shall surround the order ID in single quotes. Examples:
     * <pre>
     * formatConfirmation("123ABC", 1) should return
     *   "Order '123ABC' contains 1 item."
     * formatConfirmation("XYZ-999", 3)" should return
     *   "Order 'XYZ-999' contains 3 items."
     * </pre>
     * Requires `orderId` only contains digits, hyphens, or letters 'A' - 'Z'; `itemCount` is
     * non-negative.
     */
    public static String formatConfirmation(String orderId, int itemCount) {
        // Implementation constraint: Use Java's ternary operator (`?:`) to give "item" the
        // appropriate plurality.

        // TODO: Implement this method according to its specifications.
        throw new UnsupportedOperationException();
    }

    // TODO: Declare, document, and implement a `main()` method calling the above methods and
    // printing a result.
}
