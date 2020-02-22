#include<cstdio>
#include<cmath>
#include <iostream>
#include <map>

#define N 5729

// Primes in this range precomputed and pasted
int primes[N] = { 2, ..., 56501 };

std::map<int,int> factorizeNum(int m) {
    
    std::map<int,int> res;

    int aux = m;
    int primesearch = sqrt(m);

    for(int pos = 0; pos < N && primes[pos] <= primesearch && aux > 1; pos++) {
        while (aux%primes[pos] == 0) {
            aux /= primes[pos];

            std::map<int, int>::iterator it = res.find(primes[pos]); 
            if (it != res.end())
                it->second += 1;
            else
                res[primes[pos]] = 1;
        }
    }
    
    if (aux != 1) {
        res[aux] = 1;
    }

    return res;

}

int main() {

    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {

        if(m == 0 or m == 1 or n >= m) {
            printf("%d divides %d!\n", m, n);
            continue;
        } 
        
        std::map<int, int> values = factorizeNum(m);
        bool div = true;

        for(auto entry : values) {

            int cont = entry.second;
            int prime = entry.first;

            if (cont == 1) {
                if (prime <= n) {
                    continue;
                } else {
                    div = false;
                    break;
                }
            } else {

                for(int i = 2; i <= n; i++) {
                    if (cont == 0) {
                        break;
                    }
                    int x = i;
                    while (cont > 0 && (x%prime) == 0) {
                        cont--;
                        x /= prime;
                    }
                }
                if (cont > 0) {
                    div = false;
                    break;
                }

            }
        }

        if (div) {
            printf("%d divides %d!\n", m, n);     
        } else {
            printf("%d does not divide %d!\n", m, n);
        }        

    }

}