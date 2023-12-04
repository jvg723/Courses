public class Main {

    static int N = 40000;

    public static void main(String[] args) {

        System.out.println("Starting list construction.");
        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            list.addBack(i);
        }
        System.out.println("Finished constructing list.");

        long startTime;
        long endTime;

        startTime = System.currentTimeMillis();
        list.addAt(N - 1, -1);
        endTime = System.currentTimeMillis();
        //System.out.println(list);
        System.out.println("Adding one element took " + (endTime - startTime) + " milliseconds.");

        startTime = System.currentTimeMillis();
        list.hasDuplicates();
        endTime = System.currentTimeMillis();
        //System.out.println(list);
        System.out.println(
                "Checking for duplicates took " + (endTime - startTime) + " milliseconds.");
    }
}
