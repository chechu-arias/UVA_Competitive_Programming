#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int y = 0, borr = 0, del = 0, n = 0, x = 0, ncards = 52;
    string aux, line;
    vector<string> cards;
    cin >> n;
	getline(cin, line);
    for(int rep = 1; rep <= n; rep++) {
		getline(cin, line);
		char* pch = strtok((char*)line.c_str()  , " ");
		while(pch != NULL) {
			cards.push_back(pch);
			pch = strtok(NULL , " ");
		}
        /* for(int i = 0; i < ncards; i++) {
            cin >> aux;
			cards.push_back(aux);
			//cards.insert(cards.begin(), 1, aux);
        }*/
        for(int i = 0; i < 3; i++) {
            const char * card = cards[26-borr].c_str();
			//cout << card << '\n';
            if(card[0] == 'A' || card[0] == 'K' || card[0] == 'Q' || card[0] == 'J' || card[0] == 'T') {
                x = 10;
            } else {
                string s = card;
                x = stoi(s.substr(0, 1));
            }
			//cout << x << '\n';
            y += x;
            del = 10 - x;
			borr += del + 1;
            //cout << del << " " << borr << '\n';
			if(del == 0) {
				//cout << cards.at(27-borr) << '\n';
				cards.erase(cards.begin() + 27 - borr);
			} else {
				/* for(int k = 0; k < del; k++) {
					cout << cards.at(27+k-borr);
                }*/
				cards.erase(cards.begin() + 27 - borr, cards.begin() + 28 + del - borr);
			}
            //for(int j = 0; j <= del; j++) {
                
            //}
            /*cout << cards.size() << '\n';
            for(string s : cards) {
				cout << s << " ";
            }
			cout << '\n';*/
        }
		cout << "Case " << rep << ": " << cards[y-1] << '\n';
        cards.clear();
        borr = 0;
        y = 0;
    }
}
