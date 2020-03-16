#include <iostream>
#include <cstdio>
#include <math.h>

#define INF 1e10

using namespace std;

typedef struct {
    double x, y;
}coord;

coord nodes[100];

double calc_distance(coord i, coord j) {
    return  sqrt( pow(i.x - j.x,2)+pow(i.y - j.y,2) );
}

double getDistanceOfMST(int n_nodes) {

    double dists[n_nodes][n_nodes];

    for (int i = 0; i < n_nodes; i++) {
        for (int j = i; j < n_nodes; j++) {
            double aux = calc_distance(nodes[i], nodes[j]);
            dists[i][j] = aux;
            dists[j][i] = aux;
        }                
    }

    double res = 0;
    int no_edge = 0;
    bool selected[n_nodes] = {};
    selected[0] = true;
    
    int x;
    int y;
    
    while (no_edge < n_nodes - 1) {

        double min = INF;
        x = 0;
        y = 0;
    
        for (int i = 0; i < n_nodes; i++) {
            if (selected[i]) {
                for (int j = 0; j < n_nodes; j++) {
                    if (!selected[j]) {
                        if (min > dists[i][j]) {
                            min = dists[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        res += min;
        selected[y] = true;
        no_edge++;
    }

    return res;

}

int main() {

    int n_cases;
    cin >> n_cases;

    for (int c = 0; c < n_cases; c++) {

        if(c) cout << "\n";

        int n_nodes;
        cin >> n_nodes;

        for (int n = 0; n < n_nodes; n++)
            cin >> nodes[n].x >> nodes[n].y;
        

        double res = getDistanceOfMST(n_nodes);
        printf("%.2f\n", res);

    }
    
    return 0;

}