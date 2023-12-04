public class OopGraphDemo {
    public static void main(String[] args) {
        Graph g = new OopGraph();

        // Create graph from lec 22, slide 38.

        // Add vertices
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addVertex("D");
        g.addVertex("E");

        // Add edges
        g.connectVertices("A", "C", 5);
        g.connectVertices("B", "A", 2);
        g.connectVertices("B", "C", 1);
        g.connectVertices("B", "D", 4);
        g.connectVertices("C", "D", -3);

        // Print adjacency
        for (Vertex v : g.vertices()) {
            System.out.print(v.label() + ": [");
            boolean first = true;
            for (Edge e : v.outgoingEdges()) {
                if (!first) {
                    System.out.print(", ");
                }
                first = false;
                System.out.print(e.destination().label() + "(" + e.weight() + ")");
            }
            System.out.println("]");
        }
    }
}
