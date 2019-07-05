#include <iostream>
#include <string>

using namespace std;

//enum Position {+x, -x, +y, -y, +z, -z};

int main() {
	int n; //aux_res, aux_inp;
	string input;
	string res;
	//map<string, Position> convers;
	
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