#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* args[]) {
    int npart, budget, nhotels, nweeks, nweeks_aux, cost_hotel, disp_hotel, res;

    while(cin >> npart >> budget >> nhotels >> nweeks) {
        res = 0;
        //cout << budget << '\n';
        while(nhotels > 0) {
            nhotels --;
            cin >> cost_hotel;
            //cout << cost_hotel << '\n';
            nweeks_aux = nweeks;
            while(nweeks_aux > 0) {
                nweeks_aux--;
                cin >> disp_hotel;
                //cout << disp_hotel << '\n';
                if(disp_hotel >= npart) {
                    //cout << (npart * cost_hotel) << "vs" << budget << '\n';
                    if((npart * cost_hotel) <= budget) {
                        if(res == 0) {
                            //cout << "Antes = 0 ->" << res << '\n';
                            res = npart * cost_hotel;
                            //cout << "Despues = 0 ->" << res << '\n';
                        } else if(res > (npart * cost_hotel)) {
                            //cout << "Antes ! 0 ->" << res << '\n';
                            res = npart * cost_hotel;
                            //cout << "Despues ! 0 ->" << res << '\n';
                        }
                    } 
                }
            }
        }
        if(res == 0) {
            cout << "stay home\n";
        } else {
            cout << to_string(res) << "\n";
        }
    }
    

    return 0;
}