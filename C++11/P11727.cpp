#include <iostream>

using namespace std;

int main(int argc, char* args[]) {
    int T, X, Y, Z;
    int cont = 1;
    cin >> T;

    while(T > 0) {
        T--;
        cin >> X >> Y >> Z;
        if(X > Y) {
            if(X > Z) {
                if(Y > Z) {
                    cout << "Case " << cont << ": " << Y;
                } else {
                    cout << "Case " << cont << ": " << Z;
                }
            } else {
                cout << "Case " << cont << ": " << X;
            }
        } else {
            if(Y > Z) {
                if(X > Z) {
                    cout << "Case " << cont << ": " << X;
                } else {
                    cout << "Case " << cont << ": " << Z;
                }
            } else {
                cout << "Case " << cont << ": " << Y;
            }
        }
        cout << '\n';
        cont++;
    }

    return 0;
}