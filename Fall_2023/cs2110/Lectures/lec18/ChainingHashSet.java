import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * A Set of elements of type `T` implemented using a Hash Table where collisions are resolved by
 * chaining elements in the same bucket using a linked list.  Table is automatically resized to
 * keep load factor below 75%.  May not contain null elements.
 */
public class ChainingHashSet<T> implements Iterable<T> {
    /** Our hash table's buckets.  Empty chains are represented by null. */
    private Node<T>[] buckets;
    
    /** The number of elements currently in this set. */
    private int size;

    /** The number of buckets that new empty sets are created with. */
    private static final int INITIAL_CAPACITY = 8;

    /**
     * Construct a new empty set.
     */
    @SuppressWarnings("unchecked")
    public ChainingHashSet() {
        // Generic arrays can't be created in Java, so must cast from a supertype and suppress the
        // "unchecked" warnings.
        buckets = (Node<T>[]) new Node[INITIAL_CAPACITY];
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
        Node<T> node = buckets[bucketFor(target)];
        while (node != null) {
            if (node.value.equals(target)) {
                return true;
            }
            node = node.next;
        }
        return false;
    }

    /**
     * Add `element` to this Set, returning true if it was not already present (false otherwise).
     * May resize table if additional element causes load factor to be exceeded.
     */
    public boolean add(T element) {
        assert element != null;

        // Determine which bucket `element` belongs in.
        int bucketId = bucketFor(element);

        // Check whether `element` is already in that bucket.
        Node<T> node = buckets[bucketId];
        while (node != null) {
            if (node.value.equals(element)) {
                return false;
            }
            node = node.next;
        }

        // Prepend `element` to its bucket.
        buckets[bucketId] = new Node<T>(element, buckets[bucketId]);
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

        int bucketId = bucketFor(element);
        // Maintain a reference to the previous node in the chain to support removal.  Null when
        // `node` is the head of the chain.
        Node<T> prev = null;
        Node<T> node = buckets[bucketId];
        while (node != null) {
            if (node.value.equals(element)) {
                if (prev == null) {
                    // If `node` is at the head of its chain, point the bucket to its successor.
                    buckets[bucketId] = node.next;
                } else {
                    // Remove `node` from chain.
                    prev.next = node.next;
                }
                size -= 1;
                return true;
            }

            prev = node;
            node = node.next;
        }

        // `element` was nowhere in the bucket's chain.
        return false;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iter();
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
        Node<T>[] oldBuckets = buckets;
        buckets = (Node<T>[]) new Node[newCapacity];

        // Iterate over all elements in the old table and add them to the new table.
        for (int b = 0; b < oldBuckets.length; ++b) {
            Node<T> node = oldBuckets[b];
            while (node != null) {
                int newB = bucketFor(node.value);
                // No need to check for duplicates, since the old table shouldn't have had any.
                buckets[newB] = new Node<T>(node.value, buckets[newB]);
                node = node.next;
            }
        }
    }

    /**
     * A node in a linked list of elements of type `E`, to be used to chain elements in the same
     * bucket.
     */
    private static class Node<E> {
        // This is a private nested class for use only by the outer class, so further encapsulation
        // of its fields provides little value.

        /** The element at this position in the chain. */
        E value;

        /** The next node in the chain, or null if this is the last node. */
        Node<E> next;

        /**
         * Construct a new Node containing the element `value` and prepend it to `next` (may be
         * null).
         */
        Node(E value, Node<E> next) {
            assert value != null;

            this.value = value;
            this.next = next;
        }
    }

    /**
     * An iterator over this set's elements.  The order of iteration is not specified.  The set must
     * not be modified while an instance of an iterator is in use.
     */
    private class Iter implements Iterator<T> {
        /** The bucket that `nextNode` is in, or `buckets.length` if nothing left to iterate. */
        private int bucket;

        /** Node containing the next value to yield, or null if nothing left to iterate. */
        private Node<T> nextNode;

        /**
         * Construct a new iterator over the outer set's elements.
         */
        public Iter() {
            bucket = 0;
            nextNode = buckets[bucket];

            // Find the first node in a non-empty bucket (if all buckets are empty, loop will
            // terminate with `nextNode == null`).
            while (nextNode == null && bucket < buckets.length - 1) {
                bucket += 1;
                nextNode = buckets[bucket];
            }
        }

        @Override
        public boolean hasNext() {
            return nextNode != null;
        }

        @Override
        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }

            T ans = nextNode.value;

            // Advance to the next node (if any) that would be yielded.  If the current node is at
            // the end of its chain, the next node will be in a later bucket.
            nextNode = nextNode.next;
            while (nextNode == null && bucket < buckets.length - 1) {
                bucket += 1;
                nextNode = buckets[bucket];
            }

            return ans;
        }
    }
}
