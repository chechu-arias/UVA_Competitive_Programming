import java.io.*;
import java.util.*;

/**
 * P11172
 */
class Main {

    public static void main(String args[]) throws IOException {
        Main inst = new Main();
        inst.problem();
    }

    void problem() throws IOException {
        int izq, der, n;
        String output = "";
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        while(n > 0) {
            n--;
            izq = input.nextInt();
            der = input.nextInt();
            if(izq > der) {
                output += ">\n";
            } else if(izq < der) {
                output += "<\n";
            } else {
                output += "=\n";
            }
        }
        System.out.print(output);
        input.close();
    }
}