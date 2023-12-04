import java.util.HashSet;
import java.util.Set;

/**
 * An `Indexer` converts a vertex label to an array index.
 */
interface Indexer<T> {

    /**
     * Convert `v` to an `int` that is zero or greater.
     */
    int toIndex(T v);
}

public class AdjMatrixGraph<VL, EL> implements Graph<VL, EL> {

    /**
     * The vertex labels in the graph.
     */
    Set<VL> vertices;

    /**
     * The number of vertices in the graph. Equals the size of `vertices`.
     */
    int numVertices;

    /**
     * The edges in the graph, represented as an adjacency matrix: `edges[v1][v2]` is non-null iff
     * there is an edge from `v1` to `v2`, in which case that array cell is the edge label.
     */
    EL[][] edges;

    /**
     * The number of edges in the graph. Equals the number of non-null cells in `edges`.
     */
    int numEdges;

    /**
     * The indexer to use for transforming vertex labels to array indices in this graph.
     */
    Indexer<VL> indexer;

    /**
     * Construct a graph that can hold at most `capacity` vertices. Requires: the range of values
     * returned by `indexer` is always in `[0..capacity)`.
     */
    public AdjMatrixGraph(int capacity, Indexer<VL> indexer) {
        vertices = new HashSet<>();
        numVertices = 0;
        edges = (EL[][]) new Object[capacity][capacity];
        numEdges = 0;
        this.indexer = indexer;
    }

    @Override
    public int numVertices() {
        return numVertices;
    }

    @Override
    public boolean hasVertex(VL v) {
        return vertices.contains(v);
    }

    @Override
    public void addVertex(VL v) {
        if (vertices.contains(v)) {
            throw new IllegalArgumentException("Vertex " + v + " is already in the graph");
        }
        vertices.add(v);
        numVertices++;
    }

    /**
     * Throw an `IllegalArgumentException` to indicate that `v` is not in the graph.
     */
    private void throwVertexNotInGraph(VL v) {
        throw new IllegalArgumentException("Vertex " + v + " is not in the graph");
    }

    @Override
    public int numEdges() {
        return numEdges;
    }

    @Override
    public EL edgeLabel(VL v1, VL v2) {
        if (!vertices.contains(v1)) {
            throwVertexNotInGraph(v1);
        }
        if (!vertices.contains(v2)) {
            throwVertexNotInGraph(v2);
        }
        EL e = edges[indexer.toIndex(v1)][indexer.toIndex(v2)];
        if (e == null) {
            throw new IllegalArgumentException("Vertex " + v1 + " has no edge to " + v2);
        }
        return e;
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
        if (!vertices.contains(v1)) {
            throwVertexNotInGraph(v1);
        }
        if (!vertices.contains(v2)) {
            throwVertexNotInGraph(v2);
        }
        int i1 = indexer.toIndex(v1);
        int i2 = indexer.toIndex(v2);
        if (edges[i1][i2] != null) {
            throw new IllegalArgumentException(
                    "Vertex " + v1 + " already has an edge to " + v2);
        }
        edges[i1][i2] = e;
    }

    @Override
    public String toString() {
        String s = "";
        for (VL v1 : vertices) {
            s += v1 + ": ";
            for (VL v2 : vertices) {
                EL e = edges[indexer.toIndex(v1)][indexer.toIndex(v2)];
                if (e != null) {
                    s += "[" + e + "] " + v2 + "; ";
                }
            }
            s += "\n";
        }
        return s;
    }
}
