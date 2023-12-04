package cs2110;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class StudentTest {
    @Test
    void testConstructorAndObservers() {
        // Typical case
        {
            Student s = new Student("joe", "giliberto");
            assertEquals("joe", s.firstName());
            assertEquals("giliberto", s.lastName());
            assertEquals(0, s.credits());
        }

        // Short names
        {
            Student s = new Student("f", "l");
            assertEquals("f", s.firstName());
            assertEquals("l", s.lastName());
        }
    }

    @Test
    void testFullName() {
        Student s = new Student("joe", "giliberto");
        assertEquals("joe", s.firstName());
        assertEquals("giliberto", s.lastName());
        assertEquals(0, s.credits());

        // Print out full name for test
        System.out.println(s.fullName());
    }

    @Test
    void testAdjustCredits() {
        Student s = new Student("first", "last");
        s.adjustCredits(3);
        assertEquals(3, s.credits());

        // A second adjustment should be cumulative
        s.adjustCredits(4);
        assertEquals(7, s.credits());

        // Negative adjustments
        s.adjustCredits(-3);
        assertEquals(4, s.credits());

        // Back to zero
        s.adjustCredits(-3);
        assertEquals(1, s.credits());

        // Print out number of credits
        System.out.println(s.credits());
    }
}
