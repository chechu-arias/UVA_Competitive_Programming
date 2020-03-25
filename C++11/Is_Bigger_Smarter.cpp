#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Elephant {

public:

    int pos, weight, iq;
    int pred, length;

    Elephant(int w, int iq, int pos) : weight(w), iq(iq), pos(pos) {
        pred = -1;
        length = 1;
    }

    bool can_precede(const Elephant &e) {
        return (this->weight < e.weight && this->iq > e.iq);
    }

    bool operator< (const Elephant &e) const {
        
        if (this->weight > e.weight) return true;
        else if (this->weight < e.weight) return false;
        else if (this->iq < e.iq) return true;
        else if (this->iq > e.iq) return false;
        else return false;

    }

    bool operator> (const Elephant &e) const {
        
        if (this->weight > e.weight) return false;
        else if (this->weight < e.weight) return true;
        else if (this->iq < e.iq) return false;
        else if (this->iq > e.iq) return true;
        else return false;

    }

};

void get_path(int e, vector<Elephant> data) {
    if (e >= 0) {
        get_path(data[e].pred, data);
        cout << data[e].pos << "\n";
    }
}

int main() {

    vector<Elephant> data;
    int w, iq, n=1;
    while(cin >> w >> iq) {
        data.push_back( Elephant(w, iq, n++) );
    }

    sort(data.begin(), data.end(), [] (const Elephant &e1, const Elephant &e2) { return e1 > e2; } );

    int max_length = 1, eleph = 0;

    for (int i = 0; i < data.size(); i++) {
        for (int j = i+1; j < data.size(); j++) {
            if ( data[i].can_precede(data[j]) && data[i].length+1 > data[j].length ) {
                data[j].length = data[i].length+1;
                data[j].pred = i;

                if (data[j].length > max_length) {
                    max_length = data[j].length;
                    eleph = j;
                }
            }

        }
    }

    cout << max_length << "\n";
    get_path(eleph, data);
    
}