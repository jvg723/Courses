import java.util.Arrays;

class ArrayBagOfStrings implements BagOfStrings {

    /**
     * The items in the bag. Indices `0..size-1` are the items and must be non-null. Indices
     * `size..items.length-1` must be null.
     */
    String[] items;

    /**
     * The number of items in the bag.
     */
    int size;

    /**
     * Create a new Bag capable of storing up to `capacity` items.
     */
    ArrayBagOfStrings(int capacity) {
        items = new String[capacity];
        size = 0;
    }

    @Override
    public void add(String newItem) {
        // Throw exception if bag is full
        if (size == items.length) {
            throw new IllegalStateException();
        }
        items[size] = newItem;
        size += 1;
    }

    @Override
    public int frequencyOf(String anItem) {
        int frequency = 0;
        for (int i = 0; i < size; i += 1) {
            if (items[i].equals(anItem)) {
                frequency += 1;
            }
        }
        return frequency;
    }

    @Override
    public String[] toArray() {
        // DISCUSS: why a copy? avoid rep exposure! see DSAJ 2.12, pp. 65-6.
        return Arrays.copyOf(items, size);
    }
}
