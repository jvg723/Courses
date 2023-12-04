/**
 * A **bag** represents a collection of items. Several copies of an item may exist in a bag. There
 * is no notion of order of items in a bag.
 * <p>
 * DISCUSS: Demos are going to have more lines of code going forward. For sake of brevity and focus
 * in lecture, we don't complete the code as perfectly as in an assignment. For example:
 * <p>
 * 1. This interface does not contain all the operations a bag might be expected to support.
 * <p>
 * 2. The classes later in the file do not necessarily handle errors in the best possible way, nor
 * check invariants in places that an assignment would require.
 */
interface Bag<T> {
    /**
     * The number of items in the bag. Example: the bag [1, 1, 2] has size 3.
     */
    int size();

    /**
     * Add `newItem` to this bag.  May throw IllegalStateException if bag has finite capacity and
     * cannot fit the new item.
     */
    void add(T newItem);

    /**
     * The number of copies of `anItem` this bag contains. Might be zero.
     */
    int frequencyOf(T anItem);

    /**
     * Create an array containing all the items in this bag. Nothing is guaranteed about the order
     * of the items in the array.
     */
    T[] toArray();
}
