import java.util.LinkedList;

public class AdjListGraph<VL, EL> implements Graph<VL, EL> {

    class Vertex {

        VL label;
        LinkedList<Edge> outgoing;

        /**
         * Constructor: a vertex with label `label`.
         */
        Vertex(VL label) {
            this.label = label;
            outgoing = new LinkedList<>();
        }
    }

    class Edge {

        EL label;
        VL to;

        /**
         * Constructor: an edge with label `label` going to `to`.
         */
        Edge(EL label, VL to) {
            this.label = label;
            this.to = to;
        }
    }

    /**
     * The vertices of the graph
     */
    LinkedList<Vertex> vertices;

    /**
     * Constructs a graph with no nodes nor edges.
     */
    public AdjListGraph() {
        vertices = new LinkedList<>();
    }

    @Override
    public int numVertices() {
        return vertices.size();
    }

    @Override
    public boolean hasVertex(VL v) {
        for (Vertex u : vertices) {
            if (u.label.equals(v)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public void addVertex(VL v) {
        if (hasVertex(v)) {
            throw new IllegalArgumentException("Vertex " + v + " is already in the graph");
        }
        Vertex u = new Vertex(v);
        vertices.addFirst(u);
    }

    @Override
    public int numEdges() {
        int e = 0;
        for (Vertex v : vertices) {
            e += v.outgoing.size();
        }
        return e;
    }

    /**
     * Throw `IllegalArgumentException` if `v` is not a vertex of the graph
     */
    private void checkInGraph(VL v) {
        if (!hasVertex(v)) {
            throwVertexNotInGraph(v);
        }
    }

    /**
     * Throw an `IllegalArgumentException` to indicate that `v` is not in the graph.
     */
    private void throwVertexNotInGraph(VL v) {
        throw new IllegalArgumentException("Vertex " + v + " is not in the graph");
    }

    @Override
    public EL edgeLabel(VL v1, VL v2) {
        for (Vertex v : vertices) {
            if (v.label.equals(v1)) {
                // v1 is in the graph
                for (Edge e : v.outgoing) {
                    if (e.to.equals(v2)) {
                        // v2 is adjacent to v1
                        return e.label;
                    }
                }
                // v2 is not adjacent to v1
                throw new IllegalArgumentException("Vertex " + v1 + " has no edge to " + v2);
            }
        }
        throwVertexNotInGraph(v1);
        return null; // unreachable statement
    }

    @Override
    public boolean hasEdge(VL v1, VL v2) {
        try {
            edgeLabel(v1, v2);
        } catch (IllegalArgumentException e) {
            return false;
        }
        return true;
    }

    @Override
    public void addEdge(VL v1, EL e, VL v2) {
        for (Vertex v : vertices) {
            if (v.label.equals(v1)) {
                // v1 is in the graph
                for (Edge f : v.outgoing) {
                    if (f.to.equals(v2)) {
                        // v2 is already adjacent to v1
                        throw new IllegalArgumentException(
                                "Vertex " + v1 + " already has an edge to " + v2);
                    }
                }
                // v2 is not already adjacent to v1; make it so
                checkInGraph(v2);
                v.outgoing.add(new Edge(e, v2));
                return;
            }
        }
        throwVertexNotInGraph(v1);
    }

    @Override
    public String toString() {
        String s = "";
        for (Vertex v : vertices) {
            s += v.label + ": ";
            for (Edge e : v.outgoing) {
                s += "[" + e.label + "] " + e.to + "; ";
            }
            s += "\n";
        }
        return s;
    }
}
