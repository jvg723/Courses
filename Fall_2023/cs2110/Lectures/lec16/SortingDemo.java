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
    @Override
    public int compare(Element a, Element b) {
        return Integer.compare(a.value, b.value);
    }
}

public class SortingDemo {
    public static void main(String[] args) {
        // Create shuffled array and a comparator to use for sorting
        Comparator<Element> cmp = new ValueComparison();
        Element[] a = makeArray(10);

        // Print shuffled array
        System.out.println(Arrays.toString(a));

        // Sort array
        Sorting.selectionSort(a, cmp);
//        Sorting.insertionSort(a, cmp);
//        Sorting.mergeSort(a, cmp);
//        Sorting.quickSort(a, cmp);

        // Print sorted array
        System.out.println(Arrays.toString(a));
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
