public class SearchDemo {
    public static void main(String[] args) {
        // Overflow demo
        int begin = 1500000000;
        int end = 1500000003;
        // Note that `begin+end` is > Integer.MAX_VALUE (2^32 - 1)
        int midNaive = (begin + end)/2;
        int midProtected = begin + (end - begin)/2;
        System.out.println("Naive average: " + midNaive + "; protected average: " + midProtected);

        // Binary search
        int[] a = {1, 2, 5, 6, 7, 9};
        int i = binarySearch(a, 0, a.length, 7);
        System.out.println("Insertion point is " + i);
    }

    /**
     * Return the index `k` in `[begin..end]` such that  `a[i] < target` for `i < k` and
     * `a[i] >= target` for `i >= k`.  Requires `0 <= begin <= end <= a.length`, `a[begin..end)` is
     * sorted in ascending order.
     */
    static int binarySearch(int[] a, int begin, int end, int target) {
        // Array view is empty; only one legal index to return
        if (begin == end) {
            return begin;
        }

        int m = begin + (end - begin)/2;
        // Guarantee: begin <= m < end

        if (a[m] < target) {
            // if a[m] < target, then m < ans; search right half
            return binarySearch(a, m + 1, end, target);
        } else {
            // ans <= m; search left half
            return binarySearch(a, begin, m, target);
        }
    }

}
