// FIXME: This class is missing specifications! (coming lec 4)

class Counter {
    int counts = 0;

    int getCount() {
        // Note: `this` is optional in Java as long as there is no shadowing
        return this.counts;
    }

    void reset() {
        this.counts = 0;
    }

    void increment() {
        this.counts += 1;
    }
}
