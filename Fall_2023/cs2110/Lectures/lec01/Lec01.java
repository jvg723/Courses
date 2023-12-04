/** Demo of an application that calls a function. */
public class Lec01 {
    /** Return number of seconds in `hours` hours. */
    static int hoursToSeconds(int hours) {
        int minutes;
        minutes = 60 * hours;
        int seconds;
        seconds = 60 * minutes;
        return seconds;
    }

    public static void main(String[] args) {
        System.out.println(hoursToSeconds(1));
    }
}
