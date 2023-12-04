import java.util.*;

/**
 * Yield elements in a binary tree in level order (BFS).
 */
public class LevelOrderIterator<T> implements Iterator<T> {
    /**
     * Contains nodes that have been discovered but whose values have not yet been yielded.
     * Nodes are added in breadth-first-search order, with left siblings preceding right siblings
     */
    private Queue<BinaryNode<T>> queue;

    /**
     * Create a new Iterator that will yield the elements in the binary tree rooted at `root` in
     * level order.
     */
    public LevelOrderIterator(BinaryNode<T> root) {
        queue = new LinkedList<>();
        queue.add(root);
    }

    @Override
    public boolean hasNext() {
        // If there are no discovered-but-unyielded nodes, then iteration is finished.
        return !queue.isEmpty();
    }

    @Override
    public T next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }

        // Remove the next node to be iterated over from the queue.
        BinaryNode<T> next = queue.remove();

        // Add its left subtree (if any) to the queue, then its right subtree.
        if (next.left() != null) {
            queue.add(next.left());
        }
        if (next.right() != null) {
            queue.add(next.right());
        }

        // Return its root value.
        return next.data();
    }
}
