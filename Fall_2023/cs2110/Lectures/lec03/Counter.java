class Counter {
    /** Class invariant: `counts` is in [0, 9999]. */
    int counts = 0;

    int getCount() {
        return counts;
    }

    void reset() {
        counts = 0;
    }

    void increment() {
        if (counts == 9999) {
            counts = 0;
        } else {
            counts += 1;
        }
    }
}

// FIXME: This class is missing specifications and access modifiers (which were
//   not introduced before this demo)
