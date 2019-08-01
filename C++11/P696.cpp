#include <iostream>

using namespace std;

int main() {
    int x, y, res;
    cin >> x >> y;
    while(x != 0) {
        if(x == 1 || y == 1) {
            if(x != 1) {
                cout << x << " knights may be placed on a " << x << " row " << y << " column board.\n";
            } else {
                cout << y << " knights may be placed on a " << x << " row " << y << " column board.\n";
            }
        } else if (x == 2 || y == 2) {
            if(x != 2) {
                res = x/2;
                if(x%4==1) res++;
                else if(res%2) res++;
                cout << res*2 << " knights may be placed on a " << x << " row " << y << " column board.\n";
            } else {
                res = y/2;
                if(y%4==1) res++;
                else if(res%2) res++;
                cout << res*2 << " knights may be placed on a " << x << " row " << y << " column board.\n";
            }
        } else {
            res = x * y;
            if(res%2) res++;
            cout << res/2 << " knights may be placed on a " << x << " row " << y << " column board.\n";
        }
        cin >> x >> y;
    }
    return 0;


}