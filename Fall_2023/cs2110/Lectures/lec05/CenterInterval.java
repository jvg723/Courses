/**
 * An interval represented by its midpoint and width.
 */
public class CenterInterval implements Interval {
    /**
     * The midpoint of this interval.
     */
    private double center;

    /**
     * The width of this interval.  Must be non-negative.
     */
    private double width;

    /**
     * Create a new CenterInterval centered at `center` with width `width`.
     */
    public CenterInterval(double center, double width) {
        this.center = center;
        this.width = width;
    }

    @Override
    public double left() {
        return center - width / 2.0;
    }

    @Override
    public double right() {
        return center + width / 2.0;
    }

    @Override
    public boolean contains(double x) {
        return Math.abs(x - center) <= width / 2.0;
    }
}
