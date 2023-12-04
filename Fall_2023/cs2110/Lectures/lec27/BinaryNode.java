/**
 * A node in a binary tree containing a value of type `T`.
 */
class BinaryNode<T> {
    /**
     * The value contained in this node.
     */
    final T data;

    /**
     * This node's left subtree; null if left subtree is empty.  Does not contain this node.
     */
    BinaryNode<T> left;

    /**
     * This node's right subtree; null if right subtree is empty.  Does not contain this node.
     */
    BinaryNode<T> right;

    /**
     * Create a new node with value `data`, left subtree `left`, and right subtree `right`.
     * Null subtree arguments represent empty trees.
     */
    BinaryNode(T data, BinaryNode<T> left, BinaryNode<T> right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }

    /**
     * Create a new leaf node with value `data`.
     */
    BinaryNode(T data) {
        this(data, null, null);
    }

    /**
     * Return the value in this node.
     */
    T data() {
        return data;
    }

    /**
     * Return this node's left subtree.
     */
    BinaryNode<T> left() {
        return left;
    }

    /**
     * Return this node's right subtree.
     */
    BinaryNode<T> right() {
        return right;
    }
}
