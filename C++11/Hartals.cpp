#include <iostream>

using namespace std;

int main() {
    int n_cases;
    cin >> n_cases;

    while(n_cases > 0) {
        n_cases--;

        int res = 0;

        int n_days, n_parties;
        cin >> n_days;
        cin >> n_parties;

        int hartals[n_parties];
        int hartal;

        for(int i = 0; i < n_parties; i++) {
            cin >> hartal;
            hartals[i] = hartal;
        }

        for(int day = 0; day <= n_days; day++) {

            int hartal_cond = (day%7);
            if (hartal_cond == 6 || hartal_cond == 0) {
                continue;
            } else {
                bool cont_cond = false;
                for (int hartal_pos = 0; hartal_pos < n_parties; hartal_pos++) {
                    if ((day%hartals[hartal_pos]) == 0) {
                        res++;
                        cont_cond = true;
                        break;
                    }
                }
                if (cont_cond) {
                    continue;
                }
            }
        }

        cout << res << "\n";
    }
}

