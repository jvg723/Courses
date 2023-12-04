import java.nio.BufferOverflowException;
import java.util.NoSuchElementException;

/**
 * A buffer of values of type T with a fixed capacity.
 * This class is not thread-safe.
 */
public class SequentialRingBuffer<T> {
    /**
     * Backing array storing the values; length is buffer capacity.
     * Elements that do not correspond to contained values are null.
     */
    private final T[] store;

    /**
     * Index of next value that will be returned by `get()`.
     */
    private int iHead;

    /**
     * Number of values currently contained in buffer.
     * Index of next element that can be written to by `put()` is:
     * @{code (iHead + size)%store.length}.
     */
    private int size;

    /**
     * Returns true if class invariant is satisfied.
     */
    private boolean checkInvariant() {
        // Note: does not check that unoccupied elements are null
        return iHead >= 0 && iHead < store.length &&
                size >= 0 && size <= store.length;
    }

    /**
     * Create a new buffer with the specified capacity.
     */
    @SuppressWarnings("unchecked")
    public SequentialRingBuffer(int capacity) {
        store = (T[]) new Object[capacity];
        iHead = 0;
        size = 0;
        assert checkInvariant();
    }

    /**
     * Returns the total capacity of the buffer (the number of elements it
     * contains when it is full).
     */
    public int capacity() {
        return store.length;
    }

    /**
     * Returns true if no element can currently be added to the buffer.
     */
    public boolean isFull() {
        assert checkInvariant();
        return size == store.length;
    }

    /**
     * Returns true if no element can be consumed from the buffer.
     */
    public boolean isEmpty() {
        assert checkInvariant();
        return size == 0;
    }

    /**
     * Returns the number of elements currently in the buffer.
     */
    public int size() {
        assert checkInvariant();
        return size;
    }

    /**
     * Append a value `x` to the buffer.
     * Throws BufferOverflowException if buffer is full.
     */
    public void put(T x) {
        assert checkInvariant();

        if (isFull()) {
            throw new BufferOverflowException();
        }

        // Compute index of next available element
        int iEnd = (iHead + size) % store.length;
        assert store[iEnd] == null;

        // Store value
        store[iEnd] = x;
        size += 1;

        assert checkInvariant();
    }

    /**
     * Remove and return the oldest value in the buffer.
     * Throws NoSuchElementException if buffer is empty.
     */
    public T get() {
        assert checkInvariant();

        if (isEmpty()) {
            throw new NoSuchElementException();
        }

        // Extract value to be returned
        T ans = store[iHead];

        // Advance head to remove value
        // (set element to null to preserve invariant and avoid memory leak)
        store[iHead] = null;
        iHead = (iHead + 1) % store.length;
        size -= 1;

        assert checkInvariant();

        return ans;
    }

    /**
     * Attempt to share bounded buffer with producer and consumer threads (unsafe!).
     * Threads wait for conditions by spinning in client code.
     */
    public static void main(String[] args) {
        // The shared buffer
        SequentialRingBuffer<Integer> b = new SequentialRingBuffer<>(1);

        // Task for producer threads to perform
        Runnable p = () -> {
            for (int i = 0; i < 10; ++i) {
                while (b.isFull()) { /* spin */ }
                b.put(i);
            }
            System.out.println("Producer done");
        };

        // Task for consumer threads to perform
        Runnable c = () -> {
            int sum = 0;
            for (int i = 0; i < 10; ++i) {
                while (b.isEmpty()) { /* spin */ }
                Integer j = b.get();
                sum += j;
            }
            System.out.println("Consumer done; sum: " + sum);
        };

        // Create and start producer and consumer threads
        int np = 5;  // Number of producer threads
        int nc = 5;  // Number of consumer threads
        for (int i = 0; i < np; ++i) {
            new Thread(p).start();
        }
        for (int i = 0; i < nc; ++i) {
            new Thread(c).start();
        }

        System.out.println("Main done");
    }
}
