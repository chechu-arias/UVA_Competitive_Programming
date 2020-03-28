#include <iostream>
#include <vector>
#include <algorithm>

#define inf 2147483647

using namespace std;

class Turtle {

public:
    int weight, capacity;

    Turtle(int w, int c) : weight(w), capacity(c) {}

    bool operator< (const Turtle &t) const {
        
        return this->capacity < t.capacity || (this->capacity == t.capacity && this->weight > t.weight);

    }

};

int main() {

    vector<Turtle> data;
    int w, s;
    while(cin >> w >> s) {
        data.push_back( Turtle(w, s) );
    }

    sort(data.begin(), data.end());

    int acc_weight[data.size()+1];
    for(int i = 0; i <= data.size(); i++)
        acc_weight[i] = inf;

    acc_weight[0] = 0;

    int length = 0;
    for (int i = 0; i < data.size(); i++) {

        for (int j = length; j >= 0; j--) {

            int w = acc_weight[j] + data[i].weight;

            if ( w <= data[i].capacity && w < acc_weight[j+1] ) {

                acc_weight[j+1] = w;
                length = max(length, j+1);

            }

        }

    }

    cout << length << "\n";


}