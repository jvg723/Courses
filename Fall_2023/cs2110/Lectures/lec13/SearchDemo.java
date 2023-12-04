public class SearchDemo {

    public static void main(String[] args) {
        // Warmup exercise
        int[] a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int i = binarySearch(a, 1, 7, 4);
        System.out.println("Insertion point is " + i);
    }

    /**
     * Return the index `k` in `[begin..end]` such that  `a[i] < target` for `i < k` and
     * `a[i] >= target` for `i >= k`.  Requires `0 <= begin <= end <= a.length`, `a[begin..end)` is
     * sorted in ascending order.
     */
    static int binarySearch(int[] a, int begin, int end, int target) {
        System.out.println("binarySearch(a, " + begin + ", " + end + ", " + target +")");
        // Array view is empty; only one legal index to return
        if (begin == end) {
            System.out.println("popped a[" + begin + ".." + end + ")");
            return begin;
        }

        int m = begin + (end - begin)/2;
        // Guarantee: begin <= m < end

        if (a[m] < target) {
            // if a[m] < target, then m < ans; search right half
            int ans = binarySearch(a, m + 1, end, target);
            System.out.println("popped a[" + begin + ".." + end + ")");
            return ans;
        } else {
            // ans <= m; search left half
            int ans = binarySearch(a, begin, m, target);
            System.out.println("popped a[" + begin + ".." + end + ")");
            return ans;
        }
    }
}
