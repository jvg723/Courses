/**
 * A device that keeps track of the number of times it has been incremented, modulo 10000.
 */
public class Counter {
    /** Class invariant: `counts` is in [0, 9999]. */
    private int counts;

    /** Create a new Counter initialized with a count of zero. */
    public Counter {
        counts = 0;
    }

    /** Return the current value of this Counter's count. */
    public int getCount() {
        return counts;
    }

    /** Reset this Counter's count to zero. */
    public void reset() {
        counts = 0;
    }

    /** Increment this Counter's count.  If its count would become 10000, it rolls over to 0. */
    public void increment() {
        if (counts == 9999) {
            counts = 0;
        } else {
            counts += 1;
        }
    }
}
