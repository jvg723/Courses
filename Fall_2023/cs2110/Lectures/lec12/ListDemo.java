public class ListDemo {
    public static void main(String[] args) {
        // Raw nodes
        Node<String> n2 = new Node<>("world", null);
        Node<String> n1 = new Node<>("Hello", n2);

        // Static function
        int pos = Node.positionOf(n1, "world");
        // Instance method
        //int pos = n1.positionOf("world");

        System.out.println("Position of 'world': " + pos);

        // Encapsulating list
        LinkedList<String> list = new LinkedList<>();
        list.addBack("Do");
        list.addBack("Re");
        list.addBack("Mi");
        int pos2 = list.positionOf("Mi");
        System.out.println("Position of 'Mi': " + pos2);
    }
}
