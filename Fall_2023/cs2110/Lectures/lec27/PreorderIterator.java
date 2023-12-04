import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.NoSuchElementException;

/**
 * Yield elements in a binary tree in preorder order.  Yields the value at the root, followed by the
 * elements in the left subtree (in preorder order), followed by the elements in the right subtree
 * (in preorder order).
 */
public class PreorderIterator<T> implements Iterator<T> {
    /**
     * Contains subtrees that have been discovered but whose root values have not yet been yielded.
     * If two sibling subtrees are present, the right subtree will immediately precede the left
     * subtree (meaning the left subtree will be popped first).  The node at the top of the stack
     * contains the next element that will be yielded.
     */
    private Deque<BinaryNode<T>> stack;

    /**
     * Create a new Iterator that will yield the elements in the binary tree rooted at `root` in
     * preorder order.
     */
    public PreorderIterator(BinaryNode<T> root) {
        stack = new LinkedList<>();
        stack.push(root);
    }

    @Override
    public boolean hasNext() {
        // If there are no discovered-but-unyielded nodes, then iteration is finished.
        return !stack.isEmpty();
    }

    @Override
    public T next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }

        // Pop the next subtree to be iterated over off the stack.
        BinaryNode<T> next = stack.pop();

        // Add its right subtree (if any) to the stack, then its left subtree.
        if (next.right() != null) {
            stack.push(next.right());
        }
        if (next.left() != null) {
            stack.push(next.left());
        }

        // Return its root value.
        return next.data();
    }
}
