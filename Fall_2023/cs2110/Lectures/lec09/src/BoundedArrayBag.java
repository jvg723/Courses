import java.util.Arrays;

class BoundedArrayBag<T> implements Bag<T> {

    /**
     * The items in the bag. Indices `0..size-1` are the items and must be non-null. Indices
     * `size..items.length-1` must be null.
     */
    T[] items;

    /**
     * The number of items in the bag.
     */
    int size;

    BoundedArrayBag(int capacity) {
        //items = new T[capacity];
        // Unfortunately, Java's generics and arrays don't mix; need this instead:
        items = (T[]) new Object[capacity];
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public void add(T newItem) {
        assert newItem != null;
        if (size == items.length) {
            throw new IllegalStateException();
        }
        items[size] = newItem;
        size += 1;
    }

    @Override
    public int frequencyOf(T anItem) {
        int frequency = 0;
        for (int i = 0; i < size; i += 1) {
            if (items[i].equals(anItem)) {
                frequency += 1;
            }
        }
        return frequency;
    }

    @Override
    public T[] toArray() {
        return Arrays.copyOf(items, size);
    }
}
