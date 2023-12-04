/**
 * Represents a rational number.
 */
class Fraction {
    /**
     * The numerator of the quotient representation `num/den`.
     */
    int num;

    /**
     * The denominator of the quotient representation. Must be positive.
     * The GCD of `num` and `den` must be 1 (i.e. the fraction must be in reduced form.)
     */
    int den;

    /**
     * Return whether the class invariant is satisfied.
     */
    private void assertInv() {
        assert den > 0;
        assert gcd(num, den) == 1;
    }

    /**
     * Create a Fraction equivalent to `n/d`.  Requires `d != 0`.
     */
    Fraction(int n, int d) {
        num = n;
        den = d;
        reduce();
        assertInv();
    }

    /**
     * Create a Fraction equivalent to `n`.
     */
    Fraction(int n) {
        this(n, 1);
    }

    /**
     * Return a double-precision approximation of this fraction.
     */
    double toDouble() {
        return (double) num / den;
    }

    /**
     * Add `f` into this fraction.  Effect: this fraction represents the sum of its original value
     * and `f`.
     */
    void add(Fraction f) {
        assertInv();
        // n1/d1 + n2/d2 = (n1*d2 + n2*d1) / (d1*d2)
        num = num * f.den + f.num * den;
        den = den * f.den;
        reduce();
        assertInv();
    }

    /**
     * Make this fraction's fields be in reduced form.  Invariant may be violated on input.
     */
    void reduce() {
        int g = gcd(num, den);
        if (den < 0) {
            g = -g;
        }
        num = num / g;
        den = den / g;
    }

    /**
     * Return the greatest common divisor of `a` and `b`.
     */
    static int gcd(int a, int b) {
        // Euclidian algorithm
        while (b != 0) {
            int bPrev = b;
            b = a % b;
            a = bPrev;
        }
        return Math.abs(a);
    }
}

// FIXME: This class is missing access modifiers (which were not introduced before this demo)
