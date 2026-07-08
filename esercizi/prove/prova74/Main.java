import java.util.Scanner;
public class Main{
    public static void main(String[] args){

        DataConOrario A, B;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Data A");
        int g, m, a, o;
        System.out.println("Inserire l'anno: ");
        a = scanner.nextInt();
        System.out.println("Inserire il mese: ");
        m = scanner.nextInt();
        System.out.println("Inserire il giorno: ");
        g = scanner.nextInt();
        System.out.println("Inserire l'ora: ");
        o = scanner.nextInt();

        A = new DataConOrario(g, m, a, o);

        System.out.println("Data B");

        System.out.println("Inserire l'anno: ");
        a = scanner.nextInt();
        System.out.println("Inserire il mese: ");
        m = scanner.nextInt();
        System.out.println("Inserire il giorno: ");
        g = scanner.nextInt();
        System.out.println("Inserire l'ora: ");
        o = scanner.nextInt();
        B = new DataConOrario(g, m, a, o);
        scanner.close();
        System.out.println("Data A: " + A);
        System.out.println("Data B: " + B);

        Agenda d = new Agenda();

        if(A.precede(B)){
            System.out.println("a precede b");
            d.add(A, "nota a");
            d.add(B, "nota b");
        }else{
            d.add(B, "nota b");
            d.add(A, "nota a");
        }
        
        System.out.println(d);
        
    }
}