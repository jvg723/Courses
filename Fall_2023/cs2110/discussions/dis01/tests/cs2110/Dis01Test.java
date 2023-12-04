package cs2110;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

/**
 * Test suite for discussion activity 1.
 */
class Dis01Test {

    @Test
    void testTriangleArea() {
        // A triangle with no sides has no area
        assertEquals(0.0, Dis01.triangleArea(0.0, 0.0));

        // A 3-4-5 right triangle has area 6
        assertEquals(6.0, Dis01.triangleArea(3.0, 4.0));

        // A 1-1-sqrt(2) right triangle has area 1/2
        assertEquals(0.5, Dis01.triangleArea(1.0, 1.0));
    }

    @Test
    void testCelsiusToFahrenheit() {
        // Freezing point of water (at 1 atm): 0 degC = 32 degF
        assertEquals(32.0, Dis01.celsiusToFahrenheit(0));

        // Boiling point of water (at 1 atm): 100 degC = 212 degF
        assertEquals(212.0, Dis01.celsiusToFahrenheit(100));

        // Scales match at -40 degC = -40 degF
        assertEquals(-40.0, Dis01.celsiusToFahrenheit(-40.0));
    }

    @Test
    void testIsLeapYear() {
        // 1992 was a leap year
        assertTrue(Dis01.isLeapYear(1992));

        // 2023 is not a leap year
        assertFalse(Dis01.isLeapYear(2023));

        // 1900 was not a leap year
        assertFalse(Dis01.isLeapYear(1900));

        // 2000 was a leap year
        assertTrue(Dis01.isLeapYear(2000));
    }
}
