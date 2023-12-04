class Sleeper {
    public synchronized void foo() {
        try {
            Thread.sleep(10*1000);
        } catch (InterruptedException e) {
            // This is self-contained demo code; threads will not be interrupted.
            // Catch and rethrow to avoid having to handle in tasks.
            throw new RuntimeException(e);
        }
    }
}

public class WarmupSync {
    public static void main(String[] args) throws InterruptedException {
        Sleeper x = new Sleeper();

        Thread threadA = new Thread(() -> x.foo(), "A");  // Captures `x`
        Thread threadB = new Thread(() -> x.foo(), "B");  // Captures `x`

        threadA.start();
        Thread.sleep(2*1000);
        threadB.start();
        Thread.sleep(3*1000);
        System.out.println("Thread A state: " + threadA.getState());
        System.out.println("Thread B state: " + threadB.getState());

        // https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Thread.State.html
        // RUNNABLE: A thread executing in the Java virtual machine is in this state.
        // BLOCKED: A thread that is blocked waiting for a monitor lock is in this state.
        // WAITING: A thread that is waiting indefinitely for another thread to perform a particular
        //          action is in this state.
        // TIMED_WAITING: A thread that is sleeping or waiting for another thread to perform an
        //                action for up to a specified waiting time is in this state.
    }
}
