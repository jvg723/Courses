import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.util.Scanner;

public class AutoCloseDemo {
    /**
     * Print all lines from text file "hello.txt".
     */
    public static void main(String[] args) {
        String path = "hello.txt";
        try (Reader in = new FileReader(path)) {
            Scanner sc = new Scanner(in);
            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                System.out.println(line);
            }
            // File is closed when leaving `try` block (for any reason)
        } catch (FileNotFoundException e) {
            System.err.println("Error opening file " + path);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("Error closing file " + path);
            System.exit(1);
        }
    }
}
