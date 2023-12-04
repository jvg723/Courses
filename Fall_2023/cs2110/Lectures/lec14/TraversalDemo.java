class TraversalDemo {
    public static void main(String[] args) {
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
        System.out.println("INorder: " + expr.inorderString());
        System.out.println();
        System.out.println("INorder with parens: " + expr.inorderExprString());
        System.out.println();
        System.out.println("PREorder: " + expr.preorderString());
        System.out.println();
        System.out.println("POSTorder: " + expr.postorderString());
    }
}
