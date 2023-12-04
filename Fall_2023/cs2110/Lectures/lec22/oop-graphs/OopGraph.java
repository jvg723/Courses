import java.util.*;

/**
 * Implements the Graph interface with outgoing edges stored in Vertex objects.  Vertices are
 * tracked in a map, enabling fast lookup given their index.
 */
public class OopGraph implements Graph {
    /**
     * Map of vertex labels to vertex objects containing all vertices in this graph.
     */
    private Map<String, OopVertex> vertices;

    /**
     * Create a new OopGraph with no vertices.
     */
    public OopGraph() {
        vertices = new HashMap<>();
    }

    @Override
    public Iterable<Vertex> vertices() {
        // Defend against rep exposure by making returned value unmodifiable.
        return Collections.unmodifiableCollection(vertices.values());
    }

    @Override
    public int vertexCount() {
        return vertices.size();
    }

    @Override
    public int edgeCount() {
        // Time complexity: O(V)
        int count = 0;
        for (Vertex v : vertices()) {
            count += v.outDegree();
        }
        return count;
    }

    @Override
    public Vertex getVertex(String label) {
        Vertex ans = vertices.get(label);

        if (ans == null) {
            throw new NoSuchElementException(
                    "Graph does not contain vertex with label " + label);
        }

        return ans;
    }

    @Override
    public boolean areAdjacent(String srcLabel, String dstLabel) {
        OopVertex src = vertices.get(srcLabel);

        if (src == null) {
            throw new NoSuchElementException(
                    "Graph does not contain vertex with label " + srcLabel);
        }
        if (!vertices.containsKey(dstLabel)) {
            throw new NoSuchElementException(
                    "Graph does not contain vertex with label " + srcLabel);
        }

        return src.hasAdjacent(dstLabel);
    }

    /* Mutation methods */

    @Override
    public void addVertex(String label) {
        if (!vertices.containsKey(label)) {
            vertices.put(label, new OopVertex(label));
        }
    }

    @Override
    public void connectVertices(String srcLabel, String dstLabel, double weight) {
        OopVertex src = vertices.get(srcLabel);
        OopVertex dst = vertices.get(dstLabel);

        // Check for non-existing vertices or pre-existing edge.
        if (src == null) {
            throw new NoSuchElementException(
                    "Graph does not contain vertex with label " + srcLabel);
        }
        if (dst == null) {
            throw new NoSuchElementException(
                    "Graph does not contain vertex with label " + srcLabel);
        }
        if (src.hasAdjacent(dstLabel)) {
            throw new IllegalArgumentException(
                    "An edge already connects " + srcLabel + " to " + dstLabel);
        }

        src.addEdge(new Edge(dst, weight));
    }


    /**
     * Implements the Vertex interface by storing a map of adjacent vertex labels associated with
     * Edge objects connecting to the corresponding vertex.
     */
    private static class OopVertex implements Vertex {
        /**
         * This vertex's label.
         */
        private final String label;

        /**
         * Map associating adjacent vertex labels to Edge objects connecting to the corresponding
         * vertex.
         */
        private Map<String, Edge> outgoing;

        /**
         * Create a new Vertex with label `label` and no adjacent vertices.
         */
        public OopVertex(String label) {
            this.label = label;
            outgoing = new HashMap<>();
        }

        @Override
        public String label() {
            return label;
        }

        @Override
        public Iterable<Edge> outgoingEdges() {
            // Defend against rep exposure by making returned value unmodifiable.
            return Collections.unmodifiableCollection(outgoing.values());
        }

        @Override
        public int outDegree() {
            return outgoing.size();
        }

        /**
         * Return whether a vertex with label `dstLabel` is adjacent to this vertex.
         */
        public boolean hasAdjacent(String dstLabel) {
            return outgoing.containsKey(dstLabel);
        }

        /**
         * Add outgoing edge `edge` to this vertex's adjacency map.
         */
        void addEdge(Edge edge) {
            outgoing.put(edge.destination().label(), edge);
        }
    }
}
