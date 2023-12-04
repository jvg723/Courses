/**
 * A set of distinct characters.
 */
public class BstCharSet {
    /**
     * The root of the binary search tree containing the values in the set.
     * null if set is empty.
     */
    private BstCharNode root;

    /**
     * Add value `c` to the set.  Requires `c` is not already contained in the set.
     */
    public void add(char c) {
        if (root == null) {
            root = new BstCharNode(c);
        } else {
            // TODO: Relax precondition
            root.insert(c);
        }
    }

    /**
     * Return whether this set contains value `target`.
     */
    public boolean contains(char target) {
        if (root == null) {
            return false;
        } else {
            return root.contains(target);
        }
    }

    /**
     * Return the number of distinct values in this set.
     */
    public int size() {
        if (root == null) {
            return 0;
        } else {
            return root.size();
        }
    }
}
