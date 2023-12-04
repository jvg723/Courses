public class SumRangeDemo {
    /**
     * Return the sum of the integers from 1 to `n` (inclusive). Requires `n` is positive.
     */
    static int sumRange(int n) {
        System.out.println("Pushing frame for n = " + n);

        if (n == 1) {
            return 1;
        }
        int ans = sumRange(n - 1) + n;

        System.out.println("Popping frame for n = " + n);
        return ans;
    }

    public static void main(String[] args) {
        int upperBound = 100;
        int sum = sumRange(100);

        System.out.println("The sum of the numbers 1 to " + upperBound + " is " + sum);
    }
}
