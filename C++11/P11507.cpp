#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string input;
	string res;
	
	while(cin >> n) {
		res = "+x";
		while(n>1) {
			n--;
			cin >> input;
			if(input == "No" || input == "+x" || input == "-x") {
				continue;
			}
			if(res == "+x") {
				res = input;
				continue;
			}
			
			if(res == "-x") {
				if(input == "+y") {
					res = "-y";
				} else if (input == "-y") {
					res = "+y";
				} else if (input == "+z") {
					res = "-z";
				} else if (input == "-z") {
					res = "+z";
				}
			} else if(res == "+y") {
				if(input == "+y") {
					res = "-x";
				} else if (input == "-y") {
					res = "+x";
				}
			} else if(res == "-y") {
				if(input == "+y") {
					res = "+x";
				} else if (input == "-y") {
					res = "-x";
				}
			} else if(res == "+z") {
				if(input == "+z") {
					res = "-x";
				} else if (input == "-z") {
					res = "+x";
				}
			} else if(res == "-z") {
				if(input == "+z") {
					res = "+x";
				} else if (input == "-z") {
					res = "-x";
				}
			}
		}
		if(n == 0) {
			break;
		}
		cout << res << '\n';
		
	}
	return 0;
}