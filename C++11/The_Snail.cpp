#include <iostream>
#include <string>

using namespace std;

int main() {
    double H, U, D, F, pos;
    int day;

    while(cin >> H >> U >> D >> F) {
        if(H == 0) {
            return 0;
        }
        pos = 0;
        day = 1;
        while(pos >= 0) {
            if((day-1)*F < 100) {
                //cout << "Suma: " << U - (((day-1)*F*U)/100) << '\n';
                pos += U - (((day-1)*F*U)/100);
            }
            if(pos > H) {
                break;
            }
            pos -= D;
            if(pos < 0) {
                break;
            }
            //cout << pos << '\n';
            day++;
        }
        if(pos < 0) {
            cout << "failure on day " << day << '\n';
        } else {
           cout << "success on day " << day << '\n'; 
        }
    }
    return 0;
}