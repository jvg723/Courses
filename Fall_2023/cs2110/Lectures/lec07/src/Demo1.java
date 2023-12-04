public class Demo1 {
    static void f1() {
        System.out.print("A");
        f2();
        System.out.print("B");
    }
    static void f2() {
        f3(true);
        System.out.print("C");
    }
    static void f3(boolean x) {
        if (x) { throw new RuntimeException("x should have been false"); }
        System.out.print("D");
    }

    public static void main(String[] args) {
        f1();
    }
}
