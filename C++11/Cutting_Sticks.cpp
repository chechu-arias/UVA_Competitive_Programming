#include <iostream>

using namespace std;

typedef struct {
    int start, end, cost;
} cut;

int main() {
    
    while (true) {

        int L;
        cin >> L;

        if (L == 0) break;

        int n_cuts;
        cin >> n_cuts;

        int cuts[n_cuts];

        for(int c = 0; c < n_cuts; c++) {
            int ind;
            cin >> ind;
            cuts[c] = ind;
        }
        
        int e = L;
        int s = cuts[n_cuts-1];
        cut dp[n_cuts+1][n_cuts+1] = {};

        for (int i = 0; i <= n_cuts; i++) {

            int j = n_cuts-i;

            cut aux = {s, e, 0};

            dp[i][j] = aux;
            e = s;

            if (j == 1) s = 0;
            else s = cuts[j-2];
            
        }

        for (int i = n_cuts-1; i >= 0; i--) {

            for (int j = 0; j <= i; j++) {

                int k = i-j;

                cut c1 = dp[j+1][k];
                cut c2 = dp[j][k+1];

                int min_v = INT32_MAX;
                for (int aux = j+1; aux+k <= n_cuts; aux++) {
                    int aux2 = n_cuts-aux+1;
                    if ( (dp[aux][k].cost + dp[j][aux2].cost) < min_v ) min_v = (dp[aux][k].cost + dp[j][aux2].cost);
                }

                cut aux = {c1.start, c2.end, (c2.end - c1.start + min_v ) };
                dp[j][k] = aux;
                
            }

        }

        cout << "The minimum cutting is " << dp[0][0].cost << ".\n";
        
    }

}