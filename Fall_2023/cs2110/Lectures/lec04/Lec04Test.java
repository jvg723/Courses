import org.junit.jupiter.api.Test;

import java.util.Random;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test cases for the `qSolve()` function whose specification was given in lecture 4.
 * An absolute tolerance of 1e-13 is used (somewhat arbitrarily) for all floating-point comparisons.
 */
class Lec04Test {

    /** Test when the equation has a single real root of multiplicity 2. */
    @Test
    void testQSolveMultiplicity2() {
        // x^2 = 0
        assertEquals(0, Lec04.qSolve(1, 0, 0), 1e-13);

        // (x - 1)^2 = 0
        assertEquals(1, Lec04.qSolve(1, -2, 1), 1e-13);
    }

    /** Test many equations by verifying that the returned value is a root. */
    @Test
    void testQSolveRandom() {
        // Create a random number generater with a fixed seed (so the coefficients will not change
        // when the test case is re-run).
        Random rng = new Random(1);

        // Generate many random equations with coefficients in [-10, 10)
        for (int i = 0; i < 100; ++i) {
            // Ensure `a` is non-zero (starts positive, but may flip signs below)
            double a = rng.nextDouble(Math.ulp(1), 10);
            double b = rng.nextDouble(-10, 10);
            double c = rng.nextDouble(-10, 10);
            // Ensure that discriminant is positive to avoid violating precondition
            if (b * b < 4 * a * c) {
                a = -a;
            }

            double x = Lec04.qSolve(a, b, c);
            // Verify that returned value solves the equation
            assertEquals(0, a * x * x + b * x + c, 1e-13);
        }
    }

    /* The following test case assumes underspecified behavior and is therefore invalid.  It might
       pass, or it might not. */

//    /** Test for a particular root when the equation has two real roots. */
//    @Test
//    void testQSolveMultiplicity1() {
//        // x*(x - 1) = 0
//        // Invalid test: specification does not specify which root will be returned
//        assertEquals(0, Lec04.qSolve(1, -1, 0), 1e-13);
//        assertEquals(1, Lec04.qSolve(1, -1, 0), 1e-13);
//    }

    /* The following test cases violate preconditions and are therefore invalid tests (the
       behavior of the function under test is undefined for their inputs). */

//    /** Test the degenerate case of a linear equation. */
//    @Test
//    void testQSolveLinear() {
//        // Invalid test: violates precondition `a != 0`
//        assertEquals(1, Lec04.qSolve(0, 1, -1), 1e-13);
//    }

    /** Test when the equation has two complex roots. */
//    @Test
//    void testQSolveComplex() {
//        // Invalid test: violates precondition `b^2 >= 4*a*c`
//        double a = 1;
//        double b = 0;
//        double c = 1;
//        double x = Lec04.qSolve(a, b, c);
//        assertEquals(0, a*x*x + b*x + c, 1e-13);
//    }
}
