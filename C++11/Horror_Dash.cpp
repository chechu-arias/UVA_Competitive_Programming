#include <iostream>

using namespace std;

int main() {

	int T, N, v_al;
	int cont = 1;
	int max = -1;
	
	cin >> T;
	while(T--) {
		cin >> N;
		while(N--) {
			cin >> v_al;
			if(v_al > max) {
				max = v_al;
			}
		}
		cout << "Case " << cont << ": " << max << '\n';
		cont++;
		max = -1;
	}

}