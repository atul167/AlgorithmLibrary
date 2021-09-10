import java.io.*;
import java.util.*;

interface Lion {
    // Abstract method
    void displayLion();

    //Default method
    default void roars() {
        System.out.println("Lion Roars.");
    }
}

interface Tiger {
    // Abstract method
    void displayTiger();

    //Default method
    default void roars() {
        System.out.println("Tiger Roars.");
    }

}



class Liger implements Lion, Tiger {
    Liger() {
        System.out.println("Liger constructor.");
    }

    @Override
    public void displayLion() {
        System.out.println("Display lion");
    }

    @Override
    public void displayTiger() {
        System.out.println("Display tiger");
    }

    @Override
    public void roars() {
        Lion.super.roars();
        Tiger.super.roars();
    }
}

public class Main {
    public static void main(String[] args) {
        Liger liger = new Liger();
        liger.roars();
    }
}
