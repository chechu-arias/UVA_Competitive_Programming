#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* args[]) {
	int n, izq, der;
	string output;

	cin >> n;
	while(n > 0) {

		cin >> izq;
		cin >> der;
		if(izq > der) {
			output += ">\n";
		} else if(izq < der) {
			output += "<\n";
		} else {
			output += "=\n";
		}
		n--;
	}
	cout << output;
	return 0;
}