public class Warmup {
    public static void main(String[] args) {
        Jet[] fleet = new Jet[]{ new U2() };
        Vehicle leader = fleet[0];
        System.out.println(leader.toString());
    }
}

interface Vehicle {
    String name();

    String fuel();
}

abstract class Jet implements Vehicle {
    @Override
    public String fuel() {
        return "JP-8";
    }

    @Override
    public String toString() {
        return name() + " consuming " + fuel();
    }
}

class U2 extends Jet {
    @Override
    public String name() {
        return "U-2";
    }

    @Override
    public String fuel() {
        return "JPTS";
    }
}
