#include <iostream>

using namespace std;

int main() {
	int n, x, y;
	char type;
	cin >> n;
	while(n--) {
		cin >> type >> x >> y;
		if(type == 'r') {
			if(x > y) {
				cout << y << '\n';
			} else {
				cout << x << '\n';
			}
		} else if(type == 'k') {
			int aux = x * y;
			if(aux%2) {
				cout << (aux+1)/2 << '\n';
			} else {
				cout << aux/2 << '\n';
			}
		} else if(type == 'Q') {
			if(x == y) {
				cout << (x-1) << '\n';
			} else if(x > y) {
				cout << y << '\n';
			} else {
				cout << x << '\n';
			}
		} else if(type == 'K') {
			if(x%2) x++;
			if(y%2) y++;
			cout << (x/2)*(y/2) << '\n';
		}
	}
	return 0;
}