import java.util.Iterator;

public class TreeIteratorDemo {
    public static void main(String[] args) {
        // Create expression tree for 3*(1 + 4*1)/5
        BinaryNode<String> expr =
                new BinaryNode<>("/",
                        new BinaryNode<>("*",
                                new BinaryNode<>("3"),
                                new BinaryNode<>("+",
                                        new BinaryNode<>("1"),
                                        new BinaryNode<>("*",
                                                new BinaryNode<>("4"),
                                                new BinaryNode<>("1")))),
                        new BinaryNode<>("5"));

        BinaryNode<String> tree =
                new BinaryNode<>("M",
                        new BinaryNode<>("K",
                                new BinaryNode<>("B",
                                        null,
                                        new BinaryNode<>("F",
                                                new BinaryNode("D"),
                                                new BinaryNode("H"))),
                                null),
                        new BinaryNode<>("X",
                                new BinaryNode("Q",
                                        new BinaryNode<>("P"),
                                        new BinaryNode<>("W",
                                                new BinaryNode("S"),
                                                null)),
                                null));

        // Print tree contents in desired order
//        Iterator<String> it = new PreorderIterator<>(tree);
        Iterator<String> it = new PostorderIterator<>(tree);
//        Iterator<String> it = new InorderIterator<>(tree);
//        Iterator<String> it = new LevelOrderIterator<>(tree);

        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }

        // Alternative: Iterable.forEach() / Iterator.forEachRemaining
//        it.forEachRemaining(x -> System.out.print(x + " "));

        System.out.println();
    }
}
