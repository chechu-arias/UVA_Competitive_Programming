#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <set>

using namespace std;

// Slow recursion, don't use it :)
int getDistancia(set<int> relations[1000], int inicial, int actual, int erdos, int cont) {
    while(true) {
        if(relations[actual].find(erdos) != relations[actual].end()) return 1;
        else {
            for(int i = 0; i < cont; i++) {
                if(i != actual && i != inicial && relations[actual].find(i) != relations[actual].end()) return getDistancia(relations, inicial, i, erdos, cont) + 1;
            }
        }
        break;
    }
    return -10000;
}


int main() {
	int n_cases;
    cin >> n_cases;
	string line;

	for(int i = 1; i <= n_cases; i++) {
        
        int N, P;
        cin >> N >> P;
        
        int cont = 1;
        int val_erdos;
        map<string, int> writers;
        set<int> relations[10000];

        while(N >= 0) {

            getline(cin, line);
            
            // La line son todos los autores
            line = line.substr(0, line.find(":"));
            

            string apellido;
            string nombre;

            size_t pos_apell = 0, pos_nombre = 0;

            list<string> aux;

            while ((pos_apell = line.find(",")) != string::npos) {

                apellido = line.substr(0, pos_apell);
                apellido = apellido + ",";
                line.erase(0, pos_apell + 1);

                pos_nombre = line.find(",");
                nombre = line.substr(0, pos_nombre);
                line.erase(0, pos_nombre + 1);

                apellido.erase(0, apellido.find_first_not_of(" "));
                nombre.erase(nombre.find_last_not_of(" ") + 1);

                string writer = apellido + nombre;
                aux.push_back(writer);

                try {
                    writers.at(writer);
                } catch(out_of_range e) {
                    if (writer == "Erdos, P.") val_erdos = cont;
                    writers[writer] = cont;
                    cont++;
                }

            }

            for(auto elem : aux) {
                for(auto elem2 : aux) {
                    relations[writers[elem]].insert(writers[elem2]);
                    relations[writers[elem2]].insert(writers[elem]);
                }
            }
            
            N--;
        }

        cout << "Scenario " << i << "\n";

        while(P > 0) {

            getline(cin, line);
            P--;

            string writer = line;
            writer.erase( 0, writer.find_first_not_of(" ") );
            writer.erase( writer.find_last_not_of(" ") + 1 );


            int inicial;
            try {
                inicial = writers[writer];
            } catch(out_of_range e) {
                inicial = -1;
            }

            int res = -1;
            if (inicial > 0) {

                set<int> nodes;
                nodes.insert(writers[writer]);

                set<int> visited;
                visited.insert(writers[writer]);

                int niv = 1;
                bool erdos_found = false;

                while(nodes.size() > 0) {
                    set<int> search;
                    for(auto node : nodes) {
                        if(relations[node].find(val_erdos) != relations[node].end()) {
                            erdos_found = true;
                            break;
                        }
                        search.insert(relations[node].begin(), relations[node].end());
                        visited.insert(node);
                    }
                    if(erdos_found) {
                        res = niv;
                        break;
                    }

                    nodes.clear();
                    set_difference(search.begin(), search.end(), visited.begin(), visited.end(), inserter(nodes, nodes.end()));

                    niv++;
                }
            }

            if(res < 0) {
                cout << line << " infinity\n";
            } else {
                cout << line << " " << res << "\n";
            }
            

        }

    }
}