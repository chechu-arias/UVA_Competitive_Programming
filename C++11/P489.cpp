#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<char> solution;
    set<char> rights;
    set<char> wrongs;
    string line;
    bool fin = false;
    int cont = 0;

    getline(cin, line);
    int n = atoi(line.c_str());
    while(n > 0) {
        while(getline(cin, line)) {
            for(char car : line) {
                if(cont == 0) {
                    solution.insert(car);
                }
                if(cont == 1) {
                    if(solution.find(car) != solution.end()) {
                        rights.insert(car);
                    } else {
                        wrongs.insert(car);
                    }
                    if(wrongs.size() == 7) {
                        cout << "Round " << n << '\n';
                        cout << "You lose.\n";
                        fin = true;
                        break;
                    } else if(rights.size() == solution.size()) {
                        cout << "Round " << n << '\n';
                        cout << "You win.\n";
                        fin = true;
                        break;
                    }
                }
            }
            cont++;
            if(fin) {
                break;
            }
            if(cont == 2) {
                cout << "Round " << n << '\n';
                cout << "You chickened out.\n";
                fin = true;
                break;
            }
        }
        cont = 0;
        fin = false;
        solution.clear();
        rights.clear();
        wrongs.clear();
        getline(cin, line);
        n = atoi(line.c_str());
    }
    return 0;
}