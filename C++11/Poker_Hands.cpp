#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    map<char, int> values = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, 
    {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};
    map<char, int> suits {{'C', 1}, {'D', 2}, {'H', 3}, {'S', 4}};
    string line;
    while(getline(cin, line)) {

        int flush_p1_C = 0, flush_p1_D = 0, flush_p1_H = 0, flush_p1_S = 0, flush_p2_C = 0, flush_p2_D = 0, flush_p2_H = 0, flush_p2_S = 0;
        int size = 15;
        int player_p1[size] = {0};
        int player_p2[size] = {0};

        char* card = strtok((char*)line.c_str(), " ");
        int cont = 1;
        while(card != NULL && cont <= 10) {
            int val = values.at(card[0]);
            if(cont <= 5) player_p1[val]++;
            else player_p2[val]++;

            switch(suits.at(card[1])) {
                case 1:
                    if(cont <= 5) flush_p1_C++;
                    else flush_p2_C++;
                    break;
                case 2:
                    if(cont <= 5) flush_p1_D++;
                    else flush_p2_D++;
                    break;
                case 3:
                    if(cont <= 5) flush_p1_H++;
                    else flush_p2_H++;
                    break;
                case 4:
                    if(cont <= 5) flush_p1_S++;
                    else flush_p2_S++;
                    break;
            }
            cont++;
            card = strtok(NULL, " ");
        }

        /* cout << "Suits for P1 are: " << flush_p1_C << " " << flush_p1_D << " " << flush_p1_H << " "  << flush_p1_S << "\n";
        for(int j = 1; j < size; j++) cout << player_p1[j] << " ";
        cout << "\n";
        cout << "Suits for P2 are: " << flush_p2_C << " " << flush_p2_D << " " << flush_p2_H << " "  << flush_p2_S << "\n";
        for(int j = 1; j < size; j++) cout << player_p2[j] << " ";
        cout << "\n";
 */
        int strength_p1 = 0;

        int max_p1_1 = 1, max_p1_2 = 1;
        bool flush_p1 = false;

        for(int i = 0; i < size; i++) {
            if(player_p1[i] > max_p1_1) {
                max_p1_2 = max_p1_1;
                max_p1_1 = player_p1[i];
            } else if(player_p1[i] > max_p1_2) {
                max_p1_2 = player_p1[i];
            }
        }

        if(max_p1_1 == 4) strength_p1 = 7;
        else if(max_p1_1 == 3 && max_p1_2 == 2) strength_p1 = 6;
        else if(flush_p1_C == 5 || flush_p1_D == 5 || flush_p1_H == 5 || flush_p1_S == 5) {
            strength_p1 = 5;
            flush_p1 = true;
        }
        else if(max_p1_1 == 3) strength_p1 = 3;
        else if(max_p1_1 == 2 && max_p1_2 == 2) strength_p1 = 2;
        else if(max_p1_1 == 2) strength_p1 = 1;
        else if(max_p1_1 == 1) strength_p1 = 0;

        if(strength_p1 == 5 || strength_p1 == 0) {
            for(int i = size-1; i > 0; i--) {
                if(i == size-1 && player_p1[i] == 1 && player_p1[2] == 1) {
                    if(player_p1[i-1] == 1 && player_p1[i-2] == 1 && player_p1[i-3] == 1) {
                        if(flush_p1) strength_p1 = 8;
                        else strength_p1 = 4;
                        break;
                    } else if(player_p1[i-1] == 1 && player_p1[i-2] == 1 && player_p1[3] == 1) {
                        if(flush_p1) strength_p1 = 8;
                        else strength_p1 = 4;
                        break;
                    } else if(player_p1[i-1] == 1 && player_p1[3] == 1 && player_p1[4] == 1) {
                        if(flush_p1) strength_p1 = 8;
                        else strength_p1 = 4;
                        break;
                    } else if(player_p1[3] == 1 && player_p1[4] == 1 && player_p1[5] == 1) {
                        if(flush_p1) strength_p1 = 8;
                        else strength_p1 = 4;
                        break;
                    } else {
                        break;
                    }
                } else {
                    if(player_p1[i] == 1 && i >= 5) {
                        if(player_p1[i-1] == 1 && player_p1[i-2] == 1 && player_p1[i-3] == 1 && player_p1[i-4] == 1) {
                            if(flush_p1) strength_p1 = 8;
                            else strength_p1 = 4;
                            break;
                        } else {
                            break;
                        }
                        
                    }
                }
            }
        }

        int strength_p2 = 0;

        int max_p2_1 = 1, max_p2_2 = 1;
        bool flush_p2 = false;

        for(int i = 0; i < size; i++) {
            if(player_p2[i] > max_p2_1) {
                max_p2_2 = max_p2_1;
                max_p2_1 = player_p2[i];
            } else if(player_p2[i] > max_p2_2) {
                max_p2_2 = player_p2[i];
            }
        }

        if(max_p2_1 == 4) strength_p2 = 7;
        else if(max_p2_1 == 3 && max_p2_2 == 2) strength_p2 = 6;
        else if(flush_p2_C == 5 || flush_p2_D == 5 || flush_p2_H == 5 || flush_p2_S == 5) {
            strength_p2 = 5;
            flush_p2 = true;
        }
        else if(max_p2_1 == 3) strength_p2 = 3;
        else if(max_p2_1 == 2 && max_p2_2 == 2) strength_p2 = 2;
        else if(max_p2_1 == 2) strength_p2 = 1;
        else if(max_p2_1 == 1) strength_p2 = 0;
        
        if(strength_p2 == 5 || strength_p2 == 0) {
            for(int i = size-1; i > 0; i--) {
                if(i == size-1 && player_p2[i] == 1 && player_p2[2] == 1) {
                    if(player_p2[i-1] == 1 && player_p2[i-2] == 1 && player_p2[i-3] == 1) {
                        if(flush_p2) strength_p2 = 8;
                        else strength_p2 = 4;
                        break;
                    } else if(player_p2[i-1] == 1 && player_p2[i-2] == 1 && player_p2[3] == 1) {
                        if(flush_p2) strength_p2 = 8;
                        else strength_p2 = 4;
                        break;
                    } else if(player_p2[i-1] == 1 && player_p2[3] == 1 && player_p2[4] == 1) {
                        if(flush_p2) strength_p2 = 8;
                        else strength_p2 = 4;
                        break;
                    } else if(player_p2[3] == 1 && player_p2[4] == 1 && player_p2[5] == 1) {
                        if(flush_p2) strength_p2 = 8;
                        else strength_p2 = 4;
                        break;
                    } else {
                        break;
                    }
                } else {
                    if(player_p2[i] == 1 && i >= 5) {
                        if(player_p2[i-1] == 1 && player_p2[i-2] == 1 && player_p2[i-3] == 1 && player_p2[i-4] == 1) {
                            if(flush_p2) strength_p2 = 8;
                            else strength_p2 = 4;
                            break;
                        } else {
                            break;
                        }
                        
                    }
                }
            }
        }

        //cout << "Tenemos " << strength_p1 << " vs " << strength_p2 << "\n";
        if(strength_p1 > strength_p2) {
            cout << "Black wins.\n";
        } else if(strength_p2 > strength_p1) {
            cout << "White wins.\n";
        } else {
            bool special = false;
            bool solved = false;
            int pos1 = 0, pos2 = 0;
            if(strength_p1 == 7 || strength_p1 == 6 || strength_p1 == 3 || strength_p1 == 2 || strength_p1 == 1) special = true;
            for(int i = size-1; i > 0; i--) {
                if(special) {
                    if(player_p1[i] > player_p2[i] && (player_p1[i] == 4 || player_p1[i] == 3 || (player_p1[i] == 2 && strength_p1 <= 2))) {
                        cout << "Black wins.\n";
                        solved = true;
                        break;
                    } else if(player_p1[i] < player_p2[i] && (player_p2[i] == 4 || player_p2[i] == 3 || (player_p2[i] == 2 && strength_p2 <= 2))) {
                        cout << "White wins.\n";
                        solved = true;
                        break;
                    } else if(player_p1[i] > player_p2[i] && pos1 == 0) {
                        pos1 = i;
                    } else if(player_p1[i] < player_p2[i] && pos2 == 0) {
                        pos2 = i;
                    }
                } else {
                    if(player_p1[i] > player_p2[i]) {
                        cout << "Black wins.\n";
                        solved = true;
                        break;
                    } else if(player_p1[i] < player_p2[i]) {
                        cout << "White wins.\n";
                        solved = true;
                        break;
                    }
                }
            }
            if(special && !solved && (strength_p1 == 2 || strength_p1 == 1)) {
                if(pos1 > pos2) {
                    cout << "Black wins.\n";
                    solved = true;
                } else if(pos1 < pos2) {
                    cout << "White wins.\n";
                    solved = true;
                }
            }
            if(!solved) {
               cout << "Tie.\n";
            }
            
        }

    }
    return 0;
}