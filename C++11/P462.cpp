#include <iostream>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    string line;
    map<char, int> conv = {pair<char, int>('S', 0), pair<char, int>('H', 1), pair<char, int>('D', 2), pair<char, int>('C', 3)};

    while(getline(cin, line)) {
        
        int val = 0;
        bool stoppedS = false, stoppedH = false, stoppedD = false, stoppedC = false, trump_bid = false;
        set<string> cardsS, cardsH, cardsD, cardsC;
        char* card = strtok((char*)line.c_str()  , " ");

		while(card != NULL) {
            if(card[0] == 'A') val += 4;
            if(card[0] == 'K') val += 3;
            if(card[0] == 'Q') val += 2;
            if(card[0] == 'J') val += 1;
			switch(conv.at(card[1])) {
                case 0:
                    cardsS.insert(card);
                    break;
                case 1:
                    cardsH.insert(card);
                    break;
                case 2:
                    cardsD.insert(card);
                    break;
                case 3:
                    cardsC.insert(card);
                    break;
            }
			card = strtok(NULL , " ");
		}

        if(cardsS.find("AS") != cardsS.end() || (cardsS.find("KS") != cardsS.end() && cardsS.size() >= 2) || (cardsS.find("QS") != cardsS.end() && cardsS.size() >= 3)) stoppedS = true;
        if(cardsH.find("AH") != cardsH.end() || (cardsH.find("KH") != cardsH.end() && cardsH.size() >= 2) || (cardsH.find("QH") != cardsH.end() && cardsH.size() >= 3)) stoppedH = true;
        if(cardsD.find("AD") != cardsD.end() || (cardsD.find("KD") != cardsD.end() && cardsD.size() >= 2) || (cardsD.find("QD") != cardsD.end() && cardsD.size() >= 3)) stoppedD = true;
        if(cardsC.find("AC") != cardsC.end() || (cardsC.find("KC") != cardsC.end() && cardsC.size() >= 2) || (cardsC.find("QC") != cardsC.end() && cardsC.size() >= 3)) stoppedC = true;

        if((cardsS.find("KS") != cardsS.end() && cardsS.size() == 1) || (cardsS.find("QS") != cardsS.end() && cardsS.size() <= 2)) val--;
        if((cardsH.find("KH") != cardsH.end() && cardsH.size() == 1) || (cardsH.find("QH") != cardsH.end() && cardsH.size() <= 2)) val--;
        if((cardsD.find("KD") != cardsD.end() && cardsD.size() == 1) || (cardsD.find("QD") != cardsD.end() && cardsD.size() <= 2)) val--;
        if((cardsC.find("KC") != cardsC.end() && cardsC.size() == 1) || (cardsC.find("QC") != cardsC.end() && cardsC.size() <= 2)) val--;

        if(cardsS.find("JS") != cardsS.end() && cardsS.size() <= 3) val--;
        if(cardsH.find("JH") != cardsH.end() && cardsH.size() <= 3) val--;
        if(cardsD.find("JD") != cardsD.end() && cardsD.size() <= 3) val--;
        if(cardsC.find("JC") != cardsC.end() && cardsC.size() <= 3) val--;

        if(stoppedS && stoppedH && stoppedD && stoppedC) {
            if(val >= 16) {
                cout << "BID NO-TRUMP\n";
                trump_bid = true;
            }
        }

        if(cardsS.size() == 2) val++;
        if(cardsH.size() == 2) val++;
        if(cardsD.size() == 2) val++;
        if(cardsC.size() == 2) val++;

        if(cardsS.size() <= 1) val += 2;
        if(cardsH.size() <= 1) val += 2;
        if(cardsD.size() <= 1) val += 2;
        if(cardsC.size() <= 1) val += 2;

        if(!trump_bid) {
            if(val < 14) {
                cout << "PASS\n";
            } else {
                if((cardsS.size() == max(cardsS.size(), cardsH.size())) && (cardsS.size() == max(cardsS.size(), cardsD.size())) && (cardsS.size() == max(cardsS.size(), cardsC.size()))) {
                    cout << "BID S\n";
                } else if((cardsH.size() == max(cardsH.size(), cardsS.size())) && (cardsH.size() == max(cardsH.size(), cardsD.size())) && (cardsH.size() == max(cardsH.size(), cardsC.size()))) {
                    cout << "BID H\n";
                } else if((cardsD.size() == max(cardsD.size(), cardsS.size())) && (cardsD.size() == max(cardsD.size(), cardsH.size())) && (cardsD.size() == max(cardsD.size(), cardsC.size()))) {
                    cout << "BID D\n";
                } else {
                    cout << "BID C\n";
                }
            }
        }
    }
    return 0;
}