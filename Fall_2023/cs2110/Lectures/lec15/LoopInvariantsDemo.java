public class LoopInvariantsDemo {

    /**
     * Return the number of occurrences of `target` in `items[0..size)`.
     */
    static <T> int frequencyOf(T target, T[] items, int size) {
        int count = 0;
        int i = 0;

        // Loop invariant: `count` is the number of occurrences of `target` in `items[..i)`.
        // Loop variant: `size - i`.
        while (i < size) {
            if (target.equals(items[i])) {
                count += 1;
            }
            i += 1;
        }
        return count;
    }


    /**
     * Return the smallest index `i` such that `a[i] == target`.  Requires `target` is in `a`.
     */
    static <T> int linearSearchPresent(T[] a, T target) {
        int i = 0;

        // Loop invariant: `target` is not in `a[0..i)`; `target` is in `a[i..]`.
        // Loop variant: `ans - i`
        while (!target.equals(a[i])) {
            i += 1;
        }
        return i;
    }

    /**
     * Return the smallest index `i` such that `a[i] == target`.  If `target` is not in `a`, return
     * `a.length`.
     */
    static <T> int linearSearchGeneral(T[] a, T target) {
        int i = 0;

        // Loop invariant: `target` is not in `a[0..i)`; `i` is in `[0..a.length]`.
        // Loop variant: 'ans - i'
        while (i < a.length && !target.equals(a[i])) {
            i += 1;
        }
        return i;
    }


    /**
     * Return the index `k` in `[0..a.length]` such that  `a[i] < target` for `i < k` and
     * `a[i] >= target` for `i >= k`.  Requires `a` is sorted in ascending order.
     */
    static int binarySearchLoop(int[] a, int target) {
        int begin = 0;
        int end = a.length;

        // Loop invariant: `0 <= begin <= end <= a.length`, `a[..begin) < target`,
        // `a[end..] >= target`.
        // Loop variant: end - begin
        while (begin != end) {
            // Determine midpoint index (overflow-safe).  Guarantees `begin <= m < end`.
            int m = begin + (end - begin) / 2;

            if (a[m] < target) {
                // if a[m] < target, then m < ans; eliminate left half.
                begin = m + 1;
            } else {
                // ans <= m; eliminate right half.
                end = m;
            }
        }

        // When the loop guard becomes false, all elements have been eliminated; only one legal
        // index to return.
        return begin;
    }

    /**
     * Return the index `k` in `[begin..end]` such that  `a[i] < target` for `i < k` and
     * `a[i] >= target` for `i >= k`.  Requires `0 <= begin <= end <= a.length`, `a[begin..end)` is
     * sorted in ascending order.
     */
    static int binarySearchRecursive(int[] a, int begin, int end, int target) {
        // Array view is empty; only one legal index to return.
        if (begin == end) {
            return begin;
        }

        // Determine midpoint index (overflow-safe).  Guarantees `begin <= m < end`.
        int m = begin + (end - begin) / 2;

        if (a[m] < target) {
            // if a[m] < target, then m < ans; search right half.
            return binarySearchRecursive(a, m + 1, end, target);
        } else {
            // ans <= m; search left half.
            return binarySearchRecursive(a, begin, m, target);
        }
    }
}
