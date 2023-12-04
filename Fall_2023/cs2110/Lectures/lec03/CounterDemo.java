class CounterDemo {
    public static void main(String[] args) {
        Counter counter = new Counter();

        for (int i = 1; i <= 10001; i += 1) {
            counter.increment();

            // Print counts near rollover
            if (i > 9997) {
                System.out.println("Count after " + i + " increments: " + counter.getCount());
            }
        }
    }
}
