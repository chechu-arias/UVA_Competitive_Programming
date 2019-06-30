#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(int argc, char* args[]) {
    int par = 0;
    char car;

    while(cin.get(car) && (int)car != 26) {
        if(car == '"') {
            if(par%2) {
                cout << "\'\'";
            } else {
                cout << "``";
            }
            par++;
        } else {
            cout << car;
        }
    }
    return 0;
}