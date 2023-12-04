import java.util.Arrays;

public class ArrayList<T> implements List<T> {

    /**
     * The items in the list. Indices `0..size-1` are the items and must be non-null. Indices
     * `size..items.length-1` must be null. The item at position `p` is `items[p-1]`.
     */
    private T[] items;

    /**
     * The number of items in the list.
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

    /**
     * The default capacity of a newly created ArrayList.
     */
    private final int DEFAULT_CAPACITY = 10;

    public ArrayList() {
        items = (T[]) new Object[DEFAULT_CAPACITY];
        size = 0;
        assertInv();
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public void addFront(T newItem) {
        addAt(1, newItem);
    }

    @Override
    public void addBack(T newItem) {
        addAt(size + 1, newItem);
    }

    @Override
    public void addAt(int atPosition, T newItem) {
        if (atPosition < 1 || atPosition > size + 1) {
            throw new IndexOutOfBoundsException();
        }
        assert newItem != null;
        if (size == items.length) {
            T[] biggerItemsArray = Arrays.copyOf(items, 2 * items.length);
            items = biggerItemsArray;
        }
        System.arraycopy(items, atPosition - 1, items, atPosition, size - atPosition + 1);
        items[atPosition - 1] = newItem;
        size++;
        assertInv();
    }

    @Override
    public T get(int position) {
        if (position < 1 || position > size) {
            throw new IndexOutOfBoundsException();
        }
        return items[position - 1];
    }

    @Override
    public T remove(int atPosition) {
        if (atPosition < 1 || atPosition > size) {
            throw new IndexOutOfBoundsException();
        }
        T removedItem = items[atPosition - 1];
        System.arraycopy(items, atPosition, items, atPosition - 1, size - atPosition);
        items[size - 1] = null;
        size--;
        assertInv();
        return removedItem;
    }

    @Override
    public boolean hasDuplicates() {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (items[i].equals(items[j])) {
                    return true;
                }
            }
        }
        return false;
    }
}
