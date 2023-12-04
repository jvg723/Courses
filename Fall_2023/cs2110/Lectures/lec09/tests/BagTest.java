import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class BagTest {

    /**
     * Test a newly-constructed bag.
     */
    static void testBag(Bag<Integer> bag) {
        // Test that the size of a newly-constructed bag is zero.
        assertEquals(0, bag.size());

        // Add integers 0..NUM_ITEMS-1 to the bag. Test that each add increases the size by 1 and
        // results in a frequence of 1 for that item.
        final int NUM_ITEMS = 500;
        for (int i = 0; i < NUM_ITEMS; i++) {
            bag.add(i);
            assertEquals(i + 1, bag.size());
            assertEquals(1, bag.frequencyOf(i));
        }

        // Add integers 0..NUM_ITEMS-1 to the bag, again. Test that each add increases the size
        // by 1 and results in a frequence of 2 for that item.
        for (int i = 0; i < NUM_ITEMS; i++) {
            bag.add(i);
            assertEquals(NUM_ITEMS + i + 1, bag.size());
            assertEquals(2, bag.frequencyOf(i));
        }

        // Convert the bag to an array. Test that the array length is the size of the bag.
        Object[] bagAsArray = bag.toArray();
        assertEquals(2 * NUM_ITEMS, bagAsArray.length);
        // not DISCUSS much: why `Object[]` not `Integer[]` above, and cast below? History.

        // Test that each item in the array is an integer between 0 and NUM_ITEMS.
        // Note that we don't know the order to expect items in the array.
        for (Object obj : bagAsArray) {
            Integer i = (Integer) obj;
            assertTrue(0 <= i && i < NUM_ITEMS);
        }
    }

    @Test
    void testBags() {
        // DISCUSS: we can test each implementation with the same method, thanks to use of
        // `Bag` interface.
        testBag(new BoundedArrayBag<>(1000));
        testBag(new DynamicArrayBag<>());
        testBag(new LinkedBag<>());
    }
}
