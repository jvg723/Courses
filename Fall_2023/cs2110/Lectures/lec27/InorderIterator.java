import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.NoSuchElementException;

/**
 * Yield elements in a binary tree in inorder order.  Yields the elements in the left subtree (in
 * inorder order), followed by the value at the root, followed by the elements in the right subtree
 * (in inorder order).
 */
public class InorderIterator <T> implements Iterator<T> {

    /**
     * A stack containing the unvisited subsequence of the lineage of the next node to be yielded
     * (which is at the top of the stack).  Invariant: all nodes in the stack will be in the _left_
     * subtree of ancestor nodes preceding them in the stack; if a node is at the top of the stack,
     * then all elements in its left subtree have already been yielded, but no elements from its
     * right subtree have.
     */
    private Deque<BinaryNode<T>> leftLineage;

    /**
     * Create a new Iterator that will yield the elements in the binary tree rooted at `root` in
     * inorder order.
     */
    public InorderIterator(BinaryNode<T> root) {
        leftLineage = new LinkedList<>();
        goLeft(root);
    }

    /**
     * Find the "leftmost" node in the subtree rooted at `root`, appending its lineage (starting
     * with `root` and ending with the leftmost node) to `leftLineage`.
     */
    private void goLeft(BinaryNode<T> root) {
        leftLineage.push(root);
        if (root.left() != null) {
            goLeft(root.left());
        }
    }

    @Override
    public boolean hasNext() {
        return !leftLineage.isEmpty();
    }

    @Override
    public T next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }

        // Pop the next subtree to be iterated over off the stack.
        BinaryNode<T> next = leftLineage.pop();

        // Append lineage of leftmost node in right subtree to the stack, preserving its invariant.
        if (next.right() != null) {
            goLeft(next.right());
        }

        // Return its root value.
        return next.data();
    }
}
