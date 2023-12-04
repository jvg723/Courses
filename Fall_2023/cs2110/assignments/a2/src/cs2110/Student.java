package cs2110;

/**
 * A student tracked by the CMSμ course management system.
 */
public class Student {
    /**
     * First name of this Student (may not be empty or null).
     */
    private final String firstName;

    /**
     * Last name of this Student (may not be empty or null).
     */
    private final String lastName;

    /**
     * The number of credits the student is taking. Must be non-negative.
     */
    private int numCredits;

    /**
     * Assert that this object satisfies its class invariants.
     */
    private void assertInv() {
        assert firstName  != null && firstName.isEmpty();
        assert lastName   != null && lastName.isEmpty() ;
        assert numCredits >= 0;
    }

    /**
     * Create a new Student with first name `firstName` and last name `lastName` who is not enrolled
     * for any credits.  Requires firstName and lastName are not empty.
     */
    public Student(String firstName, String lastName) {
        this.firstName= firstName;
        this.lastName = lastName;
        this.numCredits = 0;
    }

    /**
     * Return the first name of this Student.  Will not be empty.
     */
    public String firstName() {
        return this.firstName;
    }

    /**
     * Return the last name of this Student.  Will not be empty.
     */
    public String lastName() {
        return this.lastName;
    }

    /**
     * Return the full name of this student, formed by joining their first and last names separated
     * by a space.
     */
    public String fullName() {
        // Observe that, by invoking methods instead of referencing this fields, this method was
        // implemented without knowing how you will name your fields.
        return firstName() + " " + lastName();
    }

    /**
     * Return the number of credits this student is currently enrolled in.  Will not be negative.
     */
    public int credits() {
        return this.numCredits;
    }

    /**
     * Change the number of credits this student is enrolled in by `deltaCredits`. For example, if
     * this student were enrolled in 12 credits, then `this.adjustCredits(3)` would result in their
     * credits changing to 15, whereas `this.adjustCredits(-4)` would result in their credits
     * changing to 8.  Requires that the change would not cause the student's credits to become
     * negative.
     */
    void adjustCredits(int deltaCredits) {
        // This method has default visibility to prevent code in other packages from directly
        // adjusting a student's credits.
        this.numCredits = this.numCredits + deltaCredits;
        assert numCredits >= 0;
    }

    /**
     * Return the full name of this student as its string representation.
     */
    @Override
    public String toString() {
        return fullName();
    }
}
