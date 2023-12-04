import java.util.Comparator;

class Sorting {
    /**
     * Swap elements at indices `i` and `j` in array `a`.
     */
    static void swap(Object[] a, int i, int j) {
        Object tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    /**
     * Sort elements of `a` in ascending order (as determined by `cmp`) using the selection sort
     * algorithm.  Relative ordering of elements comparing as equal is not preserved.
     */
    static <T> void selectionSort(T[] a, Comparator<T> cmp) {
        // Invariant: a[0..i) is sorted, a[i..] >= a[0..i)
        int i = 0;
        while (i < a.length - 1) {
            // Find index of smallest element in a[i..]
            int jSmallest = i;
            for (int j = i + 1; j < a.length; ++j) {
                if (cmp.compare(a[j], a[jSmallest]) < 0) {
                    jSmallest = j;
                }
            }

            // Swap smallest element to extend sorted portion
            swap(a, i, jSmallest);
            i += 1;
        }
    }

    /**
     * Sort elements of `a` in ascending order (as determined by `cmp`) using the insertion sort
     * algorithm.  Relative ordering of elements comparing as equal is preserved.
     */
    static <T> void insertionSort(T[] a, Comparator<T> cmp) {
        // Invariant: a[0..i) is sorted, a[i..] is unchanged
        int i = 0;
        while (i < a.length) {
            // Slide a[i] to its sorted position in a[0..i]
            // Invariant: a[j] < a[j+1..i]
            int j = i;
            // Stability requires `>` and not `>=`
            while (j > 0 && cmp.compare(a[j - 1], a[j]) > 0) {
                swap(a, j - 1, j);
                j -= 1;
            }
            i += 1;
        }
    }

    /**
     * Sort elements of `a` in ascending order (as determined by `cmp`) using the merge sort
     * algorithm.  Relative ordering of elements comparing as equal is preserved.
     */
    static <T> void mergeSort(T[] a, Comparator<T> cmp) {
        // Allocate work array
        @SuppressWarnings("unchecked")
        T[] work = (T[]) new Object[a.length];

        // Sort entire array
        mergeSort(a, 0, a.length, cmp, work);
    }

    /**
     * Sort `a[begin..end)` in ascending order (as determined by `cmp`).  Will overwrite values in
     * scratch array `work`.  Scratch array must be at least as long as the view being sorted.
     */
    static <T> void mergeSort(T[] a, int begin, int end, Comparator<T> cmp, T[] work) {
        // Base case: an array of 0 or 1 element is already sorted
        if (end - begin <= 1) {
            return;
        }

        int mid = begin + (end - begin) / 2;
        mergeSort(a, begin, mid, cmp, work);
        mergeSort(a, mid, end, cmp, work);
        merge(a, begin, mid, end, cmp, work);
    }

    /**
     * Merge sorted subarrays `a[begin..mid)` and `a[mid..end)` into a sorted view `a[begin..end)`.
     * Will overwrite values in scratch array `work`.  Scratch array must be at least as long as
     * `end - begin`.  "Sorted" means in ascending order, as determined by `cmp`.
     */
    static <T> void merge(T[] a, int begin, int mid, int end, Comparator<T> cmp, T[] work) {
        // Ensure enough space in scratch array for a[begin..end)
        assert work.length >= end - begin;

        // Invariant: work[0..k) is sorted and contains a[begin..i) and a[mid..j),
        // a[i..mid) >= work[0..k), a[j..end) >= work[0..k)
        int i = begin;
        int j = mid;
        int k = 0;
        while (i < mid && j < end) {
            // Stability requires `<=` and not `<`
            if (cmp.compare(a[i], a[j]) <= 0) {
                work[k] = a[i];
                i += 1;
            } else {
                work[k] = a[j];
                j += 1;
            }
            k += 1;
        }

        // Copy anything remaining in left half
        System.arraycopy(a, i, work, k, mid - i);
        // Copy anything remaining in right half
        System.arraycopy(a, j, work, k, end - j);
        // Copy scratch array back to original
        System.arraycopy(work, 0, a, begin, end - begin);

//        // Copy anything remaining in left half
//        while (i < mid) {
//            work[k] = a[i];
//            i += 1;
//            k += 1;
//        }
//
//        // Copy anything remaining in right half
//        while (j < end) {
//            work[k] = a[j];
//            j += 1;
//            k += 1;
//        }
//
//        // Check that we copied all elements
//        assert k == end - begin;
//
//        // Copy scratch array back to original
//        for (k = 0; k < end - begin; ++k) {
//            a[begin + k] = work[k];
//        }
    }

    /**
     * Sort elements of `a` in ascending order (as determined by `cmp`) using the quicksort
     * algorithm.  Relative ordering of elements comparing as equal is not preserved.
     */
    static <T> void quickSort(T[] a, Comparator<T> cmp) {
        quickSort(a, 0, a.length, cmp);
    }

    /**
     * Sort `a[begin..end)` in ascending order (as determined by `cmp`).
     */
    static <T> void quickSort(T[] a, int begin, int end, Comparator<T> cmp) {
        // Fully recursive
        // Base case: an array of 0 or 1 element is already sorted
        if (end - begin <= 1) {
            return;
        }

        int iPivot = partition(a, begin, end, cmp);
        quickSort(a, begin, iPivot, cmp);
        quickSort(a, iPivot + 1, end, cmp);

        // Tail recursion optimized
        /*
        while (end - begin > 1) {
            int iPivot = partition(a, begin, end, cmp);
            if (iPivot - begin < end - iPivot + 1) {
                quickSort(a, begin, iPivot, cmp);
                begin = iPivot + 1;
            } else {
                quickSort(a, iPivot + 1, end, cmp);
                end = iPivot;
            }
        }
        */
    }

    /**
     * Partition `a[begin..end)` about a selected pivot `a[i]` such that `a[begin..i) <= a[i]` and
     * `a[i+1..end) >= a[i]` (as determined by `cmp`), returning `i`.  Requires `end > begin`.
     */
    static <T> int partition(T[] a, int begin, int end, Comparator<T> cmp) {
        // Choose pivot and swap to beginning of array view
        int iPivot = begin;  // FIXME: bad choice - leads to worst-case behavior for sorted input
        swap(a, begin, iPivot);

        // Invariant: a[begin..i) <= a[i], a(j..end) >= a[i]
        int i = begin;
        int j = end - 1;
        while (i < j) {
            // FIXME: pivot will be first among duplicates - leads to worst-base behavior for
            // duplicated input.
            if (cmp.compare(a[i], a[i + 1]) > 0) {
                swap(a, i, i + 1);
                i += 1;
            } else {
                swap(a, i + 1, j);
                j -= 1;
            }
        }
        return i;
    }

    static <T> void dutchQuickSort(T[] a, Comparator<T> cmp) {
        dutchQuickSort(a, 0, a.length, cmp);
    }
    static <T> void dutchQuickSort(T[] a, int begin, int end, Comparator<T> cmp) {
        // Base case: an array of 0 or 1 element is already sorted
        if (end - begin <= 1) {
            return;
        }

        int iPivot = dutchPartition(a, begin, end, cmp);
        dutchQuickSort(a, begin, iPivot, cmp);
        dutchQuickSort(a, iPivot + 1, end, cmp);
    }

    /**
     * Partition `a[begin..end)` about a selected pivot `a[i]` such that `a[begin..i) <= a[i]` and
     * `a[i+1..end) >= a[i]` (as determined by `cmp`), returning `i`.  Requires `end > begin`.
     */
    static <T> int dutchPartition(T[] a, int begin, int end, Comparator<T> cmp) {
        // Choose pivot
        assert end > begin;
        T p = a[begin];  // FIXME: bad choice - leads to worst-case behavior for sorted input

        // Invariant: a[begin..i) < p, a[i..m) == p, a[j..end) > p
        int i = begin;
        int m = begin;
        int j = end;

        while (m < j) {
            int c = cmp.compare(a[m], p);
            if (c < 0) {
                swap(a, i, m);
                i += 1;
                m += 1;
            } else if (c > 0) {
                j -= 1;
                swap(a, m, j);
            } else {
                m += 1;
            }
        }
        assert j > i;  // The pivot was in the array, so there must be at least one copy

        // Clamp the midpoint to the range [i..j).
        return Math.max(i, Math.min(begin + (end - begin)/2, j - 1));
    }

    /**
     * Sort elements of `a` in ascending order (as determined by `cmp`) using the heapsort
     * algorithm.  Relative ordering of elements comparing as equal is not preserved.
     */
    static <T> void heapSort(T[] a, Comparator<T> cmp) {
        // Heapify the array
        // Invariant: Subtrees rooted at a[i+1..] are heaps
        // Implication: Subtree rooted at a[i] is a semiheap
        for (int i = a.length/2 - 1; i >= 0; --i) {
            bubbleDown(a, a.length, i, cmp);
        }

        // Extract elements in descending order
        for (int i = a.length - 1; i >= 0; --i) {
            swap(a, 0, i);
            bubbleDown(a, i, 0, cmp);
        }
    }

    /**
     * Heapify the max semiheap rooted at `a[root]`, where `a[0..size)` is interpreted as a complete
     * binary tree.  Element order is determined by `cmp`.  Elements outside of the subtree rooted
     * at `a[root]` are not read or modified.
     */
    static <T> void bubbleDown(T[] a, int size, int root, Comparator<T> cmp) {
        int leftChild = 2*root + 1;
        while (leftChild < size) {
            int rightChild = leftChild + 1;
            // Determine the largest child (note that right child may not exist)
            int maxChild = (rightChild < size && cmp.compare(a[leftChild], a[rightChild]) < 0) ?
                    rightChild : leftChild;
            if (cmp.compare(a[root], a[maxChild]) >= 0) {
                return;
            }
            // FIXME (optimization): Instead of swapping, only need to move maxChild value to root;
            // writing original root value can be deferred until end.
            swap(a, root, maxChild);
            root = maxChild;
            leftChild = 2*root + 1;
        }
    }
}
