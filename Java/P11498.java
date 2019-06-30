import java.io.*;
import java.util.*;

class Main {

    public static void main(String args[]) throws IOException {
        Main inst = new Main();
        inst.problem();
    }

    void problem() throws IOException {
        int K, N, M, X, Y, kaux;
	    String output = "";
        Scanner input = new Scanner(System.in);
        K = input.nextInt();
        while(K != 0) {
            //System.out.println(K);
            N = input.nextInt();
            M = input.nextInt();
            //System.out.println(N);
            //System.out.println(M);
            kaux = K;
            while(kaux > 0) {
                kaux--;
                X = input.nextInt();
                Y = input.nextInt();
                if(X == N || Y == M) {
                    output += "divisa\n";
                } else if(X > N && Y > M) {
                     output += "NE\n";
                } else if(X > N && Y < M) {
                     output += "SE\n";
                } else if(X < N && Y > M) {
                     output += "NO\n";
                } else {
                     output += "SO\n";
                }

            }
            K = input.nextInt();
        }
        System.out.print(output);
        input.close();
    }
}