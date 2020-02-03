#include <iostream>

using namespace std;

int main(int argc, char* args[]) {
	int K, N, M, X, Y;

	cin >> K;
    while(K != 0) {
        cin >> N >> M;

        while(K--) {
            cin >> X;
            cin >> Y;
            if(X == N || Y == M) {
                cout << "divisa";
            } else if(X > N && Y > M) {
                cout << "NE";
            } else if(X > N && Y < M) {
                cout << "SE";
            } else if(X < N && Y > M) {
                cout << "NO";
             } else {
                cout << "SO";
            }
            cout << '\n';
        }
        cin >> K;
    }
	return 0;
}