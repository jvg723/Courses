import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;

/**
 * An element type for sorting demos.  Has a `value` property and an independent `id` property.
 */
class Element {
    final int value;
    final char id;

    Element(int value, char id) {
        this.value = value;
        this.id = id;
    }

    @Override
    public String toString() {
        return String.valueOf(value) + "." + id;
//        return String.valueOf(value);
    }
}

/**
 * Order `Element`s by their `value`.
 */
class ValueComparison implements Comparator<Element> {
    /** Number of times `compare()` has been called since construction or last reset. */
    private int compareCount = 0;

    @Override
    public int compare(Element a, Element b) {
        compareCount += 1;
        return Integer.compare(a.value, b.value);
    }

    /** Reset comparison counter to 0. */
    public void reset() {
        compareCount = 0;
    }

    /** Return number of comparisons since construction or last reset. */
    public int compareCount() {
        return compareCount;
    }
}

interface Sorter<T> {
    void sort(T[] a, Comparator<T> cmp);
}

public class SortingDemo {
    public static void main(String[] args) {
        //showStability(Sorting::heapSort);

        System.out.println("## Selection sort");
        dupPerf((a, cmp) -> Sorting.selectionSort(a, cmp));
        System.out.println();

        System.out.println("## Insertion sort");
        dupPerf(Sorting::insertionSort);
        System.out.println();

        System.out.println("## Merge sort");
        dupPerf(Sorting::mergeSort);
        System.out.println();

        System.out.println("## Heap sort");
        dupPerf(Sorting::heapSort);
        System.out.println();

        System.out.println("## Quicksort (Dutch)");
        dupPerf(Sorting::dutchQuickSort);
        System.out.println();

        System.out.println("## Quicksort");
        dupPerf(Sorting::quickSort);
        System.out.println();
    }

    /**
     * Print an array before and after sorting to visualize the stability of the selected algorithm.
     */
    static void showStability(Sorter<Element> sorter) {
        // Create shuffled array and a comparator to use for sorting
        Comparator<Element> cmp = new ValueComparison();
        Element[] a = makeArray(10);

        // Print shuffled array
        System.out.println(Arrays.toString(a));

        // Sort array
        sorter.sort(a, cmp);

        // Print sorted array
        System.out.println(Arrays.toString(a));
    }

    /**
     * Measure the performance of the selected sorting algorithm when the array contains all
     * duplicate values.
     */
    static void dupPerf(Sorter<Element> sorter) {
        ValueComparison cmp = new ValueComparison();
        int length = 13000;
        Element[] a;
        Element dup = new Element(0, 'a');

        // Warmup
        a = new Element[100];
        Arrays.fill(a, dup);
        for (int iter = 0; iter < 1000; ++iter) {
            sorter.sort(a, cmp);
        }

        a = new Element[length];
        Arrays.fill(a, dup);
        cmp.reset();
        long startTime = System.nanoTime();
        sorter.sort(a, cmp);
        long endTime = System.nanoTime();
        System.out.println("Time: " + 1e-9*(endTime - startTime) + " s");
        System.out.println("Comparisons: " + cmp.compareCount());
    }

    /**
     * Create and return a shuffled array of `length` Elements of arbitrary value and id.
     * Duplicate element "values" are guaranteed for `length > 1`; duplicate elemenbt "ids" are
     * guaranteed for `length > 2`.
     */
    static Element[] makeArray(int length) {
        Element[] ans = new Element[length];
        for (int i = 0; i < length; i += 2) {
            ans[i] = new Element(i / 2, 'a');
            ans[i + 1] = new Element(i / 2, 'b');
        }

        // Fisher-Yates shuffle (fixed seed)
        Random rng = new Random(1);
        for (int i = 0; i < length - 1; ++i) {
            int j = rng.nextInt(i, length);
            Sorting.swap(ans, i, j);
        }

        return ans;
    }
}
