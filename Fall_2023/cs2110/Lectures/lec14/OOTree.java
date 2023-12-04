/** A binary tree of Strings (may be empty). */
public interface OOTree {
    /** Return the number of Strings in this tree. */
    int size();

    /** Return the height of this tree (only counts non-empty nodes).  Height of leaf is 1. */
    int height();
}

/** A non-empty binary tree with left and right subtrees (which may be empty). */
class NonEmpty implements OOTree {
    /** Our left subtree. */
    private OOTree left;

    /** Our right subtree. */
    private OOTree right;

    /** The value stored at the root of this tree. */
    private String value;

    public NonEmpty(String value, OOTree left, OOTree right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }

    public NonEmpty(String value) {
        this.value = value;
        this.left = Empty.EMPTY;
        this.right = Empty.EMPTY;
    }

    public int size() {
        return left.size() + right.size() + 1;
    }
    public int height() {
        return Math.max(left.height(), right.height()) + 1;
    }
}

/** An empty binary tree. */
class Empty implements OOTree {

    public int size() {
        return 0;
    }
    public int height() {
        return 0;
    }

    /** A private constructor forces clients to use the EMPTY instance we define ("singleton"
      * pattern). */
    private Empty() {}

    public static final Empty EMPTY = new Empty();

    @Override
    public boolean equals(Object other) {
        if (other == null || other.getClass() != getClass()) {
            return false;
        }
        // All empty nodes are equivalent
        return true;
    }
}

class OOTreeDemo {
    public static void main(String[] args) {
        OOTree root = new NonEmpty("13",
                new NonEmpty("11",
                        new NonEmpty("2",
                                Empty.EMPTY,
                                new NonEmpty("6", new NonEmpty("4"), new NonEmpty("8"))),
                        Empty.EMPTY),
                new NonEmpty("24",
                        new NonEmpty("17",
                                new NonEmpty("16"),
                                new NonEmpty("23", new NonEmpty("19"), Empty.EMPTY)),
                        Empty.EMPTY));

        System.out.println("Size: " + root.size());
        System.out.println("Height: " + root.height());
    }
}
