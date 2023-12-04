/**
 * An interval represented by its endpoints.
 */
public class TwoPtInterval implements Interval {
    /**
     * The left endpoint of this interval.
     */
    private double left;

    /**
     * The right endpoint of this interval.
     */
    private double right;

    /**
     * Create a new TwoPtInterval including the numbers between `left` and `right, inclusive.
     */
    public TwoPtInterval(double left, double right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public double left() {
        return left;
    }

    @Override
    public double right() {
        return right;
    }

    @Override
    public boolean contains(double x) {
        return x >= left && x <= right;
    }
}
