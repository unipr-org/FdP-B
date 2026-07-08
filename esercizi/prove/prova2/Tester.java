package prova2;

import java.util.Scanner;

public class Tester{
    public static void main(String[] args) {
        StringLista l1 = new StringLista();
        l1.inserisciTesta("3");
        l1.inserisciTesta("7");
        l1.inserisciTesta("8");
        System.out.println("La lista attualmente è:\n" + l1);
        System.out.println("L'elemento estratto è: " + l1.estraiTesta());
        System.out.println("La lista attualmente è:\n" + l1);
        Scanner scanner = new Scanner(System.in);
        String tmp = scanner.nextLine();
        scanner.close();
        if(l1.contains(tmp))
            System.out.println("La lista contiene la stringa inserita");
        else
            System.out.println("La lista non contiene la stringa inserita");

        StringLista l1bis = l1;
        System.out.println("l1bis attualmente è:\n" + l1bis);
        if(l1.equals(l1bis))
            System.out.println("Le liste sono uguali");
        else
            System.out.println("Le liste non sono uguali");
    }

}
