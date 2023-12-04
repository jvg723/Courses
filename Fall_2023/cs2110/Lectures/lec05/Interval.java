/**
 * Represents a closed interval on the real number line.  A closed interval contains both of its
 * endpoints.
 */
public interface Interval {
    /**
     * Return this interval's left endpoint.
     */
    double left();

    /**
     * Return this interval's right endpoint.  Will not be less than left endpoint.
     */
    double right();

    /**
     * Return whether x is contained in this interval.
     */
    boolean contains(double x);
}
