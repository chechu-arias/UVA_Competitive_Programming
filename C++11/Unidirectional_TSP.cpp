#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int matrix[11][101], dp[11][101];
int pathing[11][101];

int main() {

    int rows, cols;
    while(cin >> rows >> cols) {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) cin >> matrix[i][j];
        }

        for (int i = 0; i < rows; i++) dp[i][cols-1] = matrix[i][cols-1];

        for (int i = cols-2; i >= 0; i--) {
            for (int j = 0; j < rows; j++) {

                int upleft = j > 0 ? j - 1 : rows - 1;
                int left = j;
                int downleft = j < rows -1 ? j + 1 : 0;

                int min_indic = min(upleft, min(left, downleft));
                int max_indic = max(upleft, max(left, downleft));
                int midd_indic = upleft + left + downleft - min_indic - max_indic;

                if (dp[min_indic][i+1] <= dp[midd_indic][i+1] && dp[min_indic][i+1] <= dp[max_indic][i+1] ) {

                    pathing[j][i] = min_indic;
                    dp[j][i] = dp[min_indic][i+1] + matrix[j][i];

                } else if (dp[midd_indic][i+1] <= dp[max_indic][i+1]) {

                    pathing[j][i] = midd_indic;
                    dp[j][i] = dp[midd_indic][i+1] + matrix[j][i];

                } else {

                    pathing[j][i] = max_indic;
                    dp[j][i] = dp[max_indic][i+1] + matrix[j][i];

                }
                
            }
        }

        int best_path[cols];
        best_path[0] = 0;
        for (int i = 1; i < rows; i++) {
            if (dp[i][0] < dp[best_path[0]][0]) {
                best_path[0] = i;
            }
        }

        for (int j = 1; j < cols; j++) {
            best_path[j] = pathing[best_path[j-1]][j-1];
        }
        
        for (int j = 0; j < cols-1; j++) {
            cout << (best_path[j]+1) << " ";
        }
        cout << (best_path[cols-1] + 1) << "\n";

        cout << dp[best_path[0]][0] << "\n";

    }

}