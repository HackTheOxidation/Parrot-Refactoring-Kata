package parrot;

public class EuropeanParrot implements Parrot {

    public double getSpeed() {
        return getBaseSpeed();
    }

    public String getCry() {
        return "Sqoork!";
    }
}
