import java.io.*;
import java.util.*;

/** Demo for weighted single-source shortest paths. */
public class DijkstraDemo {

    /**
     * Determine the minimum-weight paths from `start` to every vertex reachable from it.
     * Returns an association between destination vertex labels and info about a shortest path
     * to them (may not be unique).  Requires that all edge weights reachable from `start` are
     * non-negative.
     */
    static Map<String, PathEnd> shortestPaths(Vertex start) {
        // Associate vertex labels with info about the shortest-known path from `start` to that
        // vertex.  Populated as vertices are discovered (not as they are settled).
        Map<String, PathEnd> pathInfo = new LinkedHashMap<>();

        // For Dijkstra's algorithm, the frontier is a (min) priority queue.
        // An element's priority is equal to the weight of the shortest-known path from `start` to
        // the element.
        PQueue<Vertex> frontier = new PQueue<>();

        // Enqueue start vertex (which is distance 0 from itself).
        pathInfo.put(start.label(), new PathEnd(0, null));
        frontier.add(start, 0);

        while (!frontier.isEmpty()) {
            // Remove the vertex with the shortest known path distance in the frontier.
            // This distance is THE shortest distance from `start` to `v`.
            Vertex v = frontier.remove();

            // Explore all neighbors to see if this path to them is shorter than any previous ones.
            for (Edge e : v.outgoingEdges()) {
                Vertex neighbor = e.destination();

                // Distance of shortest path to `neighbor` that ends with edge `e`.
                var dist = pathInfo.get(v.label()).distance() + e.weight();

                // Update path info if neighbor has not already been discovered OR if new path is
                // better than previous best path.
                if (!pathInfo.containsKey(neighbor.label())) {
                    // This neighbor was just discovered; record this path.
                    pathInfo.put(neighbor.label(), new PathEnd(dist, new Backpointer(v, e)));
                    frontier.add(neighbor, dist);
                } else if (dist < pathInfo.get(neighbor.label()).distance()) {
                    // This new path to `neighbor` is shorter than our best previous path.
                    pathInfo.put(neighbor.label(), new PathEnd(dist, new Backpointer(v, e)));
                    frontier.updatePriority(neighbor, dist);
                }
            }
        }
        return pathInfo;
    }

    // Note: The following helper classes for representing path info are defined as "records", which
    // is a Java feature we have not discussed in class.  Records are simply a shorthand for
    // creating a class that collects a few fields together; it automatically declares fields,
    // constructors, and observers in the "obvious" way and even generates `toString()`, `equals()`,
    // and `hashCode()` methods.  When you're just collecting named values together and don't need
    // to enforce class invariants or support complicated operations, records are a convenient
    // choice.

    /**
     * Pairs an Edge with its source vertex, allowing paths to be traced backwards.
     * `edge` is null when `source` is the vertex at the start of the path.
     */
    record Backpointer(Vertex source, Edge edge) { }

    /**
     * Represents a path ending at `link.edge.destination()` along with its total weight (distance).
     */
    record PathEnd(double distance, Backpointer link) { }


    public static void main(String[] args) throws IOException {
        Graph graph = OopGraph.readDot("ticket_to_ride.dot");
        //System.out.println(graph);

        var paths = shortestPaths(graph.getVertex("Los Angeles"));
        //System.out.println(paths);
        for (Map.Entry<String, PathEnd> entry : paths.entrySet()) {
            var dst = entry.getKey();
            var end = entry.getValue();
            System.out.printf("%15s  %2.0f  %s\n", dst, end.distance(),
                    (end.link() == null) ? "" : end.link().source().label());
        }
    }
}
