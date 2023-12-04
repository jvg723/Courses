public class LinkedBag<T> implements Bag<T> {

    /**
     * The head of the linked chain of nodes representing this bag. The elements of the bag are the
     * `data` in each node of the chain. Invariant: none of the nodes may contain `null` as the data
     * element.
     */
    Node<T> firstNode;

    /**
     * The number of items in the bag. Invariant: equals the number of nodes in the chain starting
     * at `firstNode`.
     */
    int size;

    public LinkedBag() {
        firstNode = null;
        size = 0;
    }

    @Override
    public void add(T newItem) {
        Node<T> newNode = new Node<>(newItem, null);
        // DISCUSS: pause point in slides
        newNode.setNext(firstNode);

        // Node<T> newNode = new Node<>(newItem, firstNode);
        this.firstNode = newNode;
        // after pause point
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
        Node<T> currNode = firstNode;
        // DISCUSS: picture in slides
//        for (Node<T> currNode = firstNode; currNode != null; currNode = currNode.next()) { }

        while (currNode != null) {
            if (currNode.data().equals(anItem)) {
                frequency++;
            }
            currNode = currNode.next();
        }
        return frequency;

        // EXECUTE: BagTest
    }

    // We won't DISCUSS the rest of this file in class.

    @Override
    public T[] toArray() {
        // As usual, have to create Object array not T array. History.
        Object[] items = new Object[size];
        Node<T> currNode = firstNode;
        for (int i = 0; i < size; i++) {
            items[i] = currNode.data();
            currNode = currNode.next();
        }
        return (T[]) items;
    }

    private void assertInv() {
        int computedSize = 0;
        // Loop over the nodes
        Node<T> currNode = firstNode;
        while (currNode != null) {
            // Check that the node data is non-null
            assert currNode.data() != null;
            computedSize++;
            // Check that the size we've computed so far is not more than the claimed size.
            // If it were, we could stop the loop early. (Indeed we should! This would
            // turn into an infinite loop if some node in the chain pointed backward to an
            // earlier node in the chain, thus forming a "circle" or "cycle" in the object diagram.)
            assert computedSize <= size;
            currNode = currNode.next();
        }
        // Check that size is correct.
        assert computedSize == size;
    }
}
