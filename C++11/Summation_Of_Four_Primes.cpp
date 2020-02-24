#include <cstdio>
#include <iostream>
#include <cmath>

#define N 10000000

int main() {

    static bool primes[N] = { 1, 1 };
    int sqrt_v = sqrt(N);
    for (int i = 2; i <= sqrt_v; i++ ) {
        if (!primes[i])
            for (int j = i << 1; j < N; j += i )
                primes[j] = true;
    }

    int n, i;
    while (scanf("%d", &n) != EOF) {
        if (n < 8) {
            std::cout << "Impossible.\n";
            continue;
        } else if (n & 1) {
            n -= 5;
            std::cout << "2 3 ";
        } else {
            n -= 4;
            std::cout << "2 2 ";
        }

        for (i = 2; i < n; i++) {
            if(!primes[i] && !primes[n-i]) {
                break;
            }
        }

        printf("%d %d\n", i, n-i);        

    }
}