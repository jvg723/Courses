import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.NoSuchElementException;

/**
 * A Set of elements of type `T` implemented using a Hash Table where collisions are resolved by
 * chaining elements in the same bucket using a linked list.  Table is automatically resized to
 * keep load factor below 75%.  May not contain null elements.
 */
public class ListHashSet<T> {
    /** Our hash table's buckets. */
    private List<T>[] buckets;
    
    /** The number of elements currently in this set. */
    private int size;

    /** The number of buckets that new empty sets are created with. */
    private static final int INITIAL_CAPACITY = 8;

    /**
     * Construct a new empty set.
     */
    @SuppressWarnings("unchecked")
    public ListHashSet() {
        // Generic arrays can't be created in Java, so must cast from a supertype and suppress the
        // "unchecked" warnings.
        buckets = (List<T>[]) new List[INITIAL_CAPACITY];
        for (int i = 0; i < buckets.length; ++i) {
            buckets[i] = new LinkedList<>();
        }
        size = 0;
    }

    /**
     * Return the number of distinct elements currently in this set.
     */
    public int size() {
        return size;
    }

    /**
     * Return whether `target` is currently contained in this set.
     */
    public boolean contains(T target) {
        assert target != null;

        // Only need to search one bucket's chain (the one that `target` would belong in).
        List<T> chain = buckets[bucketFor(target)];
        return chain.contains(target);
    }

    /**
     * Add `element` to this Set, returning true if it was not already present (false otherwise).
     * May resize table if additional element causes load factor to be exceeded.
     */
    public boolean add(T element) {
        assert element != null;

        // Determine which bucket `element` belongs in.
        List<T> chain = buckets[bucketFor(element)];

        if (chain.contains(element)) {
            return false;
        }

        // Add `element` to its bucket.
        chain.add(element);
        size += 1;

        // Check load factor against 75% limit.
        // This expression only uses integer arithmetic and assumes table size is divisible by 4.
        if ((size - 1)/3 + 1 > buckets.length/4 && buckets.length <= Integer.MAX_VALUE/2) {
            resize(2*buckets.length);
        }

        return true;
    }

    /**
     * Remove `element` from this set and return whether it was previously contained in the set.
     * Will not resize table (no minimum load factor is enforced).
     */
    public boolean remove(T element) {
        assert element != null;

        List<T> chain = buckets[bucketFor(element)];
        boolean wasPresent = chain.remove(element);
        if (wasPresent) {
            size -= 1;
        }
        return wasPresent;
    }

    /**
     * Return the current load factor of this set's hash table.
     */
    double loadFactor() {
        return (double)size/(double)buckets.length;
    }

    /**
     * Return the index of the bucket that `element` belongs in, given our current table size.
     */
    private int bucketFor(T element) {
        // TODO: Rehash element's hashCode to improve diffusion
        int hash = element.hashCode();
        return Math.abs(hash % buckets.length);
    }

    /**
     * Resize our hash table so it has `newCapacity` buckets while containing the same elements.
     * Requires `newCapacity` is positive.
     */
    @SuppressWarnings("unchecked")
    private void resize(int newCapacity) {
        assert newCapacity > 0;

        // Replace `buckets` with empty table of new capacity, maintaining a local reference to the
        // old table.
        List<T>[] oldBuckets = buckets;
        buckets = (List<T>[]) new List[newCapacity];
        for (int i = 0; i < buckets.length; ++i) {
            buckets[i] = new LinkedList<>();
        }

        // Iterate over all elements in the old table and add them to the new table.
        for (List<T> oldChain : oldBuckets) {
            for (T element : oldChain) {
                List<T> newChain = buckets[bucketFor(element)];
                newChain.add(element);
            }
        }
    }
}
