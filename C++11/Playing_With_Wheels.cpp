#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

typedef tuple<int,int,int> ii;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const ii& lhs, const ii&rhs) const
  {
    if (reverse) return (get<0>(lhs) < get<0>(rhs));
    else return (get<0>(lhs) > get<0>(rhs));
  }
};

int getDistanceToTarget(int actual, int target) {

	int multiplicators[4] = {1000, 100, 10, 1};

	int digits_act[4];
	digits_act[0] = actual/1000;
	int aux = actual%1000;
	digits_act[1] = aux/100;
	aux = aux%100;
	digits_act[2] = aux/10;
	digits_act[3] = aux%10;

	int digits_targ[4];
	digits_targ[0] = target/1000;
	aux = target%1000;
	digits_targ[1] = aux/100;
	aux = aux%100;
	digits_targ[2] = aux/10;
	digits_targ[3] = aux%10;

	int res = 0;
	for (int i = 0; i < 4; i++) {
		int aux = abs(digits_act[i]-digits_targ[i]);
		if (aux > 5) aux = 10-aux;
		res += aux;
	}

	return res;

}

void getAdyacentNodes (int act_config, int adyac[]) {

	int multiplicators[4] = {1000, 100, 10, 1};
	int digits[4];
	digits[0] = act_config/1000;
	int aux = act_config%1000;
	digits[1] = aux/100;
	aux = aux%100;
	digits[2] = aux/10;
	digits[3] = aux%10;

	int cont = 0;
	for(int i = 0; i < 4; i++) {

		int aux_upper = act_config + multiplicators[i];
		int aux_lower = act_config - multiplicators[i];

		if(digits[i] == 9) {
			aux_upper -= 10*multiplicators[i];
		}
			
		adyac[cont++] = aux_upper;

		if(digits[i] == 0) {
			aux_lower += 10*multiplicators[i];
		}

		adyac[cont++] = aux_lower;

		//cout << "Tenemos " << aux_upper << " y " << aux_lower << "\n";

	}

}


int main() {

    int n_cases;
    cin >> n_cases;
    for (int c = 0; c < n_cases; c++) {

        int initial_config = 0;
        int digits[4];
        cin >> digits[0] >> digits[1] >> digits[2] >> digits[3];
        initial_config = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];

        int target_config = 0;
        cin >> digits[0] >> digits[1] >> digits[2] >> digits[3];
        target_config = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];

        set<int> prohib_configs;
        int n_prohibited, actual;
        cin >> n_prohibited;
        for(int i = 0; i < n_prohibited; i++) {
            cin >> digits[0] >> digits[1] >> digits[2] >> digits[3];
            actual = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];
            prohib_configs.insert(actual);
        }

		int adyac[8];
		getAdyacentNodes(target_config, adyac);
		int cont = 0;
		for (int ad : adyac) {
			if (prohib_configs.find(ad) != prohib_configs.end()) cont++;
			else break;
		}

		if (initial_config == target_config) {

			cout << 0 << "\n";

		} else if (initial_config != target_config && prohib_configs.find(target_config) != prohib_configs.end()) {

			cout << -1 << "\n";

		} else if (cont == 8) {

			cout << -1 << "\n";

		} else {

			int solution = -1;
			int seen[10000] = {};
			priority_queue<ii, vector<ii>, mycomparison> values = {};
			values.push(ii( getDistanceToTarget(initial_config, target_config), 0 , initial_config));
			//cout << "De " << initial_config << " a " << target_config << " la distancia es de " << getDistanceToTarget(initial_config, target_config) << "\n";

			while(!values.empty()) {

				ii aux = values.top();
				values.pop();

				int steps_required = get<0>(aux);
				int steps = get<1>(aux);
				int act_config = get<2>(aux);
				//cout << "Tenemos la tupla: pasos requeridos " << steps_required << " pasos " << steps << " configuracion " << act_config << "\n";
				
				
				if ( !seen[act_config] ) {

					seen[act_config] = steps;
					
					if (act_config == target_config) {
						
						solution = steps;
						break;

					} else {
						
						getAdyacentNodes(act_config, adyac);

						for (int ad : adyac) {
							
							if (prohib_configs.find(ad) == prohib_configs.end() && !seen[ad] ) {

								int steps_from_ad_required = getDistanceToTarget(ad, target_config);
								//cout << ad << " necesita " << steps_from_ad_required << " para llegar a " << target_config << "\n";
								values.push(ii(steps_from_ad_required+steps+1, steps+1, ad));
								
							}
							
						}
						

					}

				}

			}

			cout << solution << "\n";

		}

    }
}