#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {
	string line;
    
	while(getline(cin, line)) {
        int zeros = 0, zero_zero = 0, zero_one = 0;
        int size = strlen(line.c_str());
		for(int pos = 0; pos < size; pos++) {
            if(line[pos] == '0') {
                zeros++;
                if(line[(pos+1)%size] == '0') zero_zero++;
                else zero_one++;
            }
        }
        //cout << zero_zero << " " << zero_one << " " << zero_one+zero_zero << "\n";
        double prob = zero_zero;
        prob /= (zero_one+zero_zero);
        //cout << "PROBABILIDAD: " << prob << "\n";
        if(size == zeros) {
            cout << "EQUAL\n";
        } else if(prob < 0.5) {
            cout << "ROTATE\n";
        } else if(prob > 0.5) {
            cout << "SHOOT\n";
        } else {
            cout << "EQUAL\n";
        }
	}
	return 0;
}