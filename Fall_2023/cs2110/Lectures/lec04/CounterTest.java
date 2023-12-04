import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Test suite for `Counter` class.  Achieves 100% line coverage.
 */
class CounterTest {

    /** A Counter should have a count of 0 when first created. */
    @Test
    void testConstructor() {
        Counter counter = new Counter();
        assertEquals(0, counter.getCount());
    }

    /** A Counter should have a count of 0 after being reset. */
    @Test
    void testReset() {
        Counter counter = new Counter();
        counter.increment();
        counter.reset();
        assertEquals(0, counter.getCount());
    }

    /** A Counter's count should increase by 1 when incremented if not at max value. */
    @Test
    void testIncrement1() {
        Counter counter = new Counter();
        counter.increment();
        assertEquals(1, counter.getCount());
    }

    /** A Counter's count should roll over to 0 when incremented at its max value. */
    @Test
    void testIncrement2() {
        Counter counter = new Counter();
        for (int i = 0; i < 9999; ++i) {
            counter.increment();
        }
        assertEquals(9999, counter.getCount());

        counter.increment();
        assertEquals(0, counter.getCount());
    }
}