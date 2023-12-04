/**
 * Represents a point in the 2D plane.
 */
class Point {
    // Fields

    /** The abscissa (Cartesian x-coordinate) of this point in the plane. */
    final double x;

    /** The ordinate (Cartesian y-coordinate) of this point in the plane. */
    final double y;

    // Observers (TODO: specification)
    double x() { return x; }
    double y() { return y; }

    // Constructor (TODO: specification)
    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Creates a point that is shifted relative to this point by `dx` horizontally and `dy`
     * vertically.
     */
    Point shifted(double dx, double dy) {
        return new Point(x + dx, y + dy);
    }
}

// FIXME: This class is missing specifications and access modifiers (which were
//   not introduced before this demo)
