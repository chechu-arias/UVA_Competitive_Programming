#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

// Precomputing a larger value than 1000000 will get you TLE
#define N 10000

bool primes[N] = { 1, 1 };

std::vector<long long> getPrimeFactors(long long val) {
    std::vector<long long> res;
    long long aux = val;
    for(long long i = 2; i < N && i <= val/2 && aux > 1; i++) {
        if(!primes[i])
            while(aux%i==0) {
                res.push_back(i);
                aux /= i;
            }
    }
    if(aux > 1) {
        res.push_back(aux);
    }
    return res;
}

bool is_smith_number(long long val, std::vector<long long> factors) {

    int res_v = 0;
    int aux = val;
    while(aux>0) {
        res_v += aux%10;
        aux /= 10;
    }
    
    int res_f = 0;
    for(auto entry : factors) {
        int aux = entry;
        while(aux>0) {
            res_f += aux%10;
            aux /= 10;
        }
    }

    if (res_v == res_f)
        return true;
    return false;
}

int main() {

    for(int i = 2; i <= N; i++ ) {
        if(!primes[i])
            for(int j = 2*i; j < N; j += i)
                primes[j] = 1;
    }

    
    int n_cases;
    std::cin >> n_cases;
    for(int i = 0; i < n_cases; i++) {
        int number;
        std::cin >> number;
        for(long long n = number+1;;n++) {
            if((n < N && primes[n]) || n > N) {
                std::vector<long long> prime_factors = getPrimeFactors(n);
                if (prime_factors.size()>1 && is_smith_number(n, prime_factors)) {
                    std::cout << n << "\n";
                    break;
                }

            }
        }
    }
    
    
}