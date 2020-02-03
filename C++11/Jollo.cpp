#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	set<int> posib;
	int A, B, C, X, Y, max;
	bool hay_sol = false;
	while(cin >> A >> B >> C >> X >> Y) {
		if(A == 0) {
			return 0;
		}
		for(int i = 1; i <= 52; i++) {
			posib.insert(i);
		}
		posib.erase(A);
		posib.erase(B);
		posib.erase(C);
		posib.erase(X);
		posib.erase(Y);
		int ord[] = {A, B, C, X, Y};
		int n = sizeof(ord) / sizeof(ord[0]);
		sort(ord, ord + n);
		
		if(X > Y) {
			if(Y == ord[0] && (A == ord[4] || B == ord[4] || C == ord[4])) {
				cout << "-1\n";
			} else {
				if((A == ord[0] || B == ord[0] || C == ord[0]) && (Y == ord[1]) && (A == ord[4] || B == ord[4] || C == ord[4])) {
					cout << "-1\n";
				} else {
					if(X == ord[4] && Y == ord[3]) {
						for(int i = 1; i <= 52; i++) {
							if(posib.find(i) != posib.end()) {
								hay_sol = true;
								cout << i << "\n";
								break;
							}
						}
						if(!hay_sol) {
							cout << "-1\n";
						}
						hay_sol = false;
					} else {
						if((A == ord[0] || B == ord[0] || C == ord[0]) && (A == ord[1] || B == ord[1] || C == ord[1])) {
							if(A > B) {
								if(A > C) {
									if(B > C) {
										max = B;
									} else {
										max = C;
									}
								} else {
									max = A;
								}
							} else {
								if(B > C) {
									if(A > C) {
										max = A;
									} else {
										max = C;
									}
								} else {
									max = B;
								}
							}
							for(int i = max+1; i <= 52;i++) {
								if(posib.find(i) != posib.end()) {
									hay_sol = true;
									cout << i << "\n";
									break;
								}
							}
							if(!hay_sol) {
								cout << "-1\n";
							}
							hay_sol = false;
						} else {
							if((A == ord[2] || B == ord[2] || C == ord[2]) && (A == ord[3] || B == ord[3] || C == ord[3]) && X == ord[4]) {
								max = std::max(A, B);
								max = std::max(max, C);
								for(int i = max+1; i <= 52;i++) {
									if(posib.find(i) != posib.end()) {
										hay_sol = true;
										cout << i << "\n";
										break;
									}
								}
								if(!hay_sol) {
									cout << "-1\n";
								}
								hay_sol = false;
							} else {
								cout << "Error? " << A << " "  << B << " "  << C << " "  << X << " "  << Y;
								return 0;
							}
						}
					}
				}
			}
		} else {
			if(X == ord[0] && (A == ord[4] || B == ord[4] || C == ord[4])) {
				cout << "-1\n";
			} else {
				if((A == ord[0] || B == ord[0] || C == ord[0]) && (X == ord[1]) && (A == ord[4] || B == ord[4] || C == ord[4])) {
					cout << "-1\n";
				} else {
					if(Y == ord[4] && X == ord[3]) {
						for(int i = 1; i <= 52; i++) {
							if(posib.find(i) != posib.end()) {
								hay_sol = true;
								cout << i << "\n";
								break;
							}
						}
						if(!hay_sol) {
							cout << "-1\n";
						}
						hay_sol = false;
					} else {
						if((A == ord[0] || B == ord[0] || C == ord[0]) && (A == ord[1] || B == ord[1] || C == ord[1])) {
							if(A > B) {
								if(A > C) {
									if(B > C) {
										max = B;
									} else {
										max = C;
									}
								} else {
									max = A;
								}
							} else {
								if(B > C) {
									if(A > C) {
										max = A;
									} else {
										max = C;
									}
								} else {
									max = B;
								}
							}
							for(int i = max+1; i <= 52;i++) {
								if(posib.find(i) != posib.end()) {
									hay_sol = true;
									cout << i << "\n";
									break;
								}
							}
							if(!hay_sol) {
								cout << "-1\n";
							}
							hay_sol = false;
						} else {
							if((A == ord[2] || B == ord[2] || C == ord[2]) && (A == ord[3] || B == ord[3] || C == ord[3]) && Y == ord[4]) {
								max = std::max(A, B);
								max = std::max(max, C);
								for(int i = max+1; i <= 52;i++) {
									if(posib.find(i) != posib.end()) {
										hay_sol = true;
										cout << i << "\n";
										break;
									}
								}
								if(!hay_sol) {
									cout << "-1\n";
								}
								hay_sol = false;
							} else {
								cout << "Error? " << A << " "  << B << " "  << C << " "  << X << " "  << Y;
								return 0;
							}
						}
					}
				}
			}
		}
	//posib.clear();
	}
	return 0;
}