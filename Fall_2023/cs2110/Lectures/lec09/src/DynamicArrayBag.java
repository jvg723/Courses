import java.util.Arrays;

/**
 * Implements a Bag with a dynamic array.
 */
public class DynamicArrayBag<T> implements Bag<T> {

    /** Initial capacity of backing store. */
    private static final int DEFAULT_CAPACITY = 16;

    /**
     * The items in the bag. Indices `0..size-1` are the items and must be non-null. Indices
     * `size..items.length-1` must be null.
     */
    private T[] items;

    /**
     * The number of items in the bag.
     */
    private int size;

    private void assertInv() {
        for (int i = 0; i < size; i++) {
            assert items[i] != null;
        }
        for (int i = size; i < items.length; i++) {
            assert items[i] == null;
        }
    }

    public DynamicArrayBag() {
        items = (T[]) new Object[DEFAULT_CAPACITY];
        assertInv();
    }

    @Override
    public void add(T newItem) {
        // DISCUSS: you know how to do this -- you did it in A2.
        assert newItem != null;
        if (size == items.length) {
            T[] biggerItemsArray = Arrays.copyOf(items, 2 * items.length);
            items = biggerItemsArray;
        }
        items[size] = newItem;
        size++;
        assertInv();
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public int frequencyOf(T anItem) {
        int frequency = 0;
        for (int i = 0; i < size; i++) {
            if (items[i].equals(anItem)) {
                frequency++;
            }
        }
        return frequency;
    }

    @Override
    public T[] toArray() {
        return Arrays.copyOf(items, size);
    }

    // EXECUTE: test suite
}


