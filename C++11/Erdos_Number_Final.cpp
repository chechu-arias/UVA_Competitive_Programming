#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <set>

using namespace std;

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

        int results[cont] = {0};

        set<int> nodes;
        nodes.insert(val_erdos);

        set<int> visited;
        visited.insert(val_erdos);

        int niv = 1;

        while(nodes.size() > 0) {
            set<int> search;
            for(auto node : nodes) {
                search.insert(relations[node].begin(), relations[node].end());
                visited.insert(node);
            }
            for(auto elem : search) {
                if(results[elem] == 0) {
                    results[elem] = niv;
                }
            }
            nodes.clear();
            set_difference(search.begin(), search.end(), visited.begin(), visited.end(), inserter(nodes, nodes.end()));

            niv++;
        }
        

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

            if(inicial < 0 || (results[inicial] == 0 && inicial != val_erdos)) {
                cout << line << " infinity\n";
            } else {
                cout << line << " " << results[inicial] << "\n";
            }            

        }

    }
}