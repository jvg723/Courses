class Lec02Demo {
    public static void main(String[] args) {
        /* Counter demo */
        System.out.println("# Counter demo");

        // Declare a variable that can reference a counter
        Counter c;
        // Create a new counter object and store a reference in the variable
        c = new Counter();

        // Call an observer method on the counter
        int n = c.getCount();
        System.out.println("Initial count: " + n);
        c.increment();
        // Note that `n` has not changed; must call observer again to get new count
        System.out.println("Count after incrementing: " + c.getCount());
        c.reset();
        System.out.println("Count after resetting: " + c.getCount());

        /* Stopwatch demo */
        System.out.println();
        System.out.println("# Stopwatch demo");

        Stopwatch timer = new Stopwatch();
        timer.start();
        System.out.println("Running? " + timer.isRunning());
        System.out.println("Time since starting: " + timer.ellapsed() + " ns");
    }
}
