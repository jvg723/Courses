// FIXME: This class is missing specifications! (coming lec 4)

class Stopwatch {
    long startTime;
    long endTime;
    boolean running;

    void start() {
        startTime = System.nanoTime();
        running = true;
    }

    void stop() {
        endTime = System.nanoTime();
        running = false;
    }

    boolean isRunning() {
        return running;
    }

    long ellapsed() {
        if (running) {
            return System.nanoTime() - startTime;
        } else {
            return endTime - startTime;
        }
    }
}
