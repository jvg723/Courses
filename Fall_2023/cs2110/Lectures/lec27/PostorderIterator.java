import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.NoSuchElementException;

/**
 * Yield elements in a binary tree in postorder order.  Yields the elements in the left subtree (in
 * postorder order), followed by the elements in the right subtree (in postorder order), followed by
 * the value at the root.
 */
public class PostorderIterator<T> implements Iterator<T> {

    /**
     * A stack containing the lineage of the next node to be yielded (which is at the top of the
     * stack).  Invariant: if a node is at the top of the stack, then all of its descendants have
     * already been yielded.
     */
    private Deque<BinaryNode<T>> lineage;

    /**
     * Create a new Iterator that will yield the elements in the binary tree rooted at `root` in
     * postorder order.
     */
    public PostorderIterator(BinaryNode<T> root) {
        lineage = new LinkedList<>();
        findNextLeaf(root);
    }

    /**
     * Search tree rooted at `root` for its first leaf (in postorder order), adding its lineage
     * (starting with `root` and ending with the first leaf) to `lineage`.  `root` may be null (in
     * which case nothing is done).
     */
    private void findNextLeaf(BinaryNode<T> root) {
        // Base case.
        if (root == null) {
            return;
        }

        // Add starting point to ancestry.
        lineage.push(root);

        // If starting point is not itself a leaf, recurse on left subtree if non-empty, otherwise
        // right subtree.
        if (root.left() != null) {
            findNextLeaf(root.left());
        } else {
            findNextLeaf(root.right());
        }
    }

    @Override
    public boolean hasNext() {
        return !lineage.isEmpty();
    }

    @Override
    public T next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }

        // Extract next node to be yielded from top of stack.
        BinaryNode<T> next = lineage.pop();

        // Restore invariant on `lineage`: if new top of stack was `next`'s parent and `next` was
        // its _left_ child, search its right subtree for the next leaf.
        if (!lineage.isEmpty()) {
            BinaryNode<T> top = lineage.peek();
            // Deliberately evaluate parent-child relationship using `==` to test reference equality
            if (next == top.left()) {
                findNextLeaf(top.right());
            }
        }

        return next.data();
    }
}
