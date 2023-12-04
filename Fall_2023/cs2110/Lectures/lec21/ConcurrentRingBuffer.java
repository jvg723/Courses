/**
 * A buffer of values of type T with a fixed capacity.
 * This class is thread-safe.
 */
public class ConcurrentRingBuffer<T> {
    /**
     * Backing array storing the values; length is buffer capacity.
     * Elements that do not correspond to contained values are null.
     * Contents guarded by: this
     */
    private final T[] store;

    /**
     * Index of next value that will be returned by `get()`.
     * Guarded by: this
     */
    private int iHead;

    /**
     * Number of values currently contained in buffer.
     * Index of next element that can be written to by `put()` is:
     * @{code (iHead + size)%store.length}.
     * Guarded by: this
     */
    private int size;

    /**
     * Returns true if class invariant is satisfied.
     */
    private synchronized boolean checkInvariant() {
        // Note: does not check that unoccupied elements are null
        return iHead >= 0 && iHead < store.length &&
                size >= 0 && size <= store.length;
    }

    /**
     * Create a new buffer with the specified capacity.
     */
    @SuppressWarnings("unchecked")
    public ConcurrentRingBuffer(int capacity) {
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
    public synchronized boolean isFull() {
        assert checkInvariant();
        return size == store.length;
    }

    /**
     * Returns true if no element can be consumed from the buffer.
     */
    public synchronized boolean isEmpty() {
        assert checkInvariant();
        return size == 0;
    }

    /**
     * Returns the number of elements currently in the buffer.
     */
    public synchronized int size() {
        assert checkInvariant();
        return size;
    }

    /**
     * Append a value `x` to the buffer.
     * Blocks until value is added.
     */
    public synchronized void put(T x) throws InterruptedException {
        assert checkInvariant();

        // Block until buffer is not full
        while (isFull()) {
            wait();
        }

        // Compute index of next available element
        int iEnd = (iHead + size) % store.length;
        assert store[iEnd] == null;

        // Store value and wake any consumers
        store[iEnd] = x;
        size += 1;
        notifyAll();

        assert checkInvariant();
    }

    /**
     * Remove and return the oldest value in the buffer.
     * Blocks until value is returned.
     */
    public synchronized T get() throws InterruptedException {
        assert checkInvariant();

        // Block until buffer is non-empty
        while (isEmpty()) {
            wait();
        }

        // Extract value to be returned
        T ans = store[iHead];

        // Advance head to remove value and wake any producers
        // (set element to null to preserve invariant and avoid memory leak)
        store[iHead] = null;
        iHead = (iHead + 1) % store.length;
        size -= 1;
        notifyAll();

        assert checkInvariant();

        return ans;
    }

    /**
     * Attempt to share bounded buffer with producer and consumer threads.
     * Blocking is encapsulated in the buffer's operations.
     */
    public static void main(String[] args) {
        // The shared buffer
        ConcurrentRingBuffer<Integer> b = new ConcurrentRingBuffer<>(1);

        // Task for producer threads to perform
        Runnable p = () -> {
            try {
                for (int i = 0; i < 10; ++i) {
                    b.put(i);
                }
                System.out.println("Producer done");
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        };

        // Task for consumer threads to perform
        Runnable c = () -> {
            try {
                int sum = 0;
                for (int i = 0; i < 10; ++i) {
                    Integer j = b.get();
                    sum += j;
                }
                System.out.println("Consumer done; sum: " + sum);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
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
