/**
 * Graph<VL, EL> represents a directed graph whose vertices are labeled with values of type VL
 * and edges with EL.
 */
public interface Graph<VL, EL> {

    // Vertex Operations

    /**
     * The number of vertices in the graph.
     */
    int numVertices();

    /**
     * Whether vertex `v` is in the graph.
     */
    boolean hasVertex(VL v);

    /**
     * Add vertex `v` to the graph. Throws `IllegalArgumentException` if `v` is already in the
     * graph.
     */
    void addVertex(VL v);

    // Edge Operations

    /**
     * The number of edges in the graph.
     */
    int numEdges();

    /**
     * The label on the edge from vertex `v1` to vertex `v2`. Throws `IllegalArgumentException` if
     * there is no edge between those vertices, or if either vertex is not in the graph.
     */
    EL edgeLabel(VL v1, VL v2);

    /**
     * Whether the graph has vertices `v1` and `v2` and an edge from `v1` to `v2`.
     */
    boolean hasEdge(VL v1, VL v2);

    /**
     * Add an edge with label `e` from vertex `v1` to vertex `v2`. Throws `IllegalArgumentException`
     * if there is no vertex `v1` or `v2`, or if there is already an edge between those vertices.
     */
    void addEdge(VL v1, EL e, VL v2);
}