import java.time.LocalDate;
import java.util.Map;
import java.util.TreeMap;

public class MapDemo {
    public static void main(String[] args) {
        Map<String, LocalDate> bdays = new TreeMap<>();

        bdays.put("Alan Turing", LocalDate.of(1912, 6, 23));
        bdays.put("John von Neumann", LocalDate.of(1903, 12, 28));

        System.out.println();
        System.out.println("Turing was born on " + bdays.get("Alan Turing"));
        for (String name : bdays.keySet()) {
            System.out.println(name + " was born on " + bdays.get(name));
        }

        System.out.println();
        System.out.println("Do I know Katherine Johnson’s birthday? " +
                (bdays.containsKey("Katherine Johnson") ? "yes" : "no"));

    }
}
