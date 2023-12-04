public class Main {

    /**
     * Construct the example graph from the lecture slides and print it.
     */
    static void printExampleGraph(Graph<Character, Integer> g) {
        g.addVertex('A');
        g.addVertex('B');
        g.addVertex('C');
        g.addVertex('D');
        g.addVertex('E');
        g.addEdge('A', 5, 'C');
        g.addEdge('B', 2, 'A');
        g.addEdge('C', -3, 'D');
        g.addEdge('B', 1, 'C');
        g.addEdge('B', 4, 'D');
        System.out.println(g);
    }

    public static void main(String[] args) {
        Graph<Character, Integer> g_adj = new AdjListGraph<>();
        Graph<Character, Integer> g_mat = new AdjMatrixGraph<>(26,
                (Character c) -> {
                    if (!('A' <= c && c <= 'Z')) {
                        throw new IllegalArgumentException("Illegal vertex label " + c);
                    }
                    return c - 'A';
                });
        System.out.println("Adjacency list:");
        printExampleGraph(g_adj);
        System.out.println("Adjacency matrix:");
        printExampleGraph(g_mat);
    }
}
