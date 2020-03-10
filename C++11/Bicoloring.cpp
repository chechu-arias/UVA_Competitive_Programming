#include <iostream>
#include <vector>
#include <sstream>
#include <set>

#define color_black 1
#define color_red 2

class Adyacente {
public:
    int dest, coste;
    Adyacente(int dest, int coste) {
        this->dest = dest;
        this->coste = coste;
    }
};

class Grafo {
public:
    bool directed;
    int numNodos, numAristas;
    std::vector<int> gradosEntrada;
    std::vector<std::vector <Adyacente> > adyacentes;

    Grafo(int numNodos, bool directed) {
        this->directed = directed;
        this->numNodos = numNodos;
        this->numAristas = 0;
        gradosEntrada.resize(numNodos, 0);
        adyacentes.resize(numNodos);
    }

    void insertarArista(int origen, int dest, int coste) {
        Adyacente ady(dest, coste);
        adyacentes[origen].push_back(ady);
        gradosEntrada[dest]++;
        numAristas++;
        if(!directed) {
            Adyacente ady(origen, coste);
            adyacentes[dest].push_back(ady);
            gradosEntrada[origen]++;
            numAristas++;
        }
    }

    int getArista(int origen, int dest) {
        for (auto ady : adyacentes[origen]) {
            if (ady.dest == dest)
                return ady.coste;
        }
        return 0;
    }

    bool existeArista(int origen, int dest) {
        for (auto ady : adyacentes[origen]) {
            if (ady.dest == dest)
                return true;
        }
        return false;
    }

    void eliminarArista(int origen, int dest) {
        for (unsigned int i = 0; i < adyacentes[origen].size(); i++) {
            Adyacente ady = adyacentes[origen][i];
            if (ady.dest == dest) {
                adyacentes[origen].erase(adyacentes[origen].begin() + i);
                gradosEntrada[origen]--;
                numAristas--;
            }
        }
        if(!directed) {
           for (unsigned int i = 0; i < adyacentes[dest].size(); i++) {
                Adyacente ady = adyacentes[dest][i];
                if (ady.dest == origen) {
                    adyacentes[dest].erase(adyacentes[dest].begin() + i);
                    gradosEntrada[dest]--;
                    numAristas--;
                }
            } 
        }
    }

    std::string toString() {
        std::stringstream res;
        for(int i = 0; i < numNodos; i++) {
            res << "Vertice: " << i;
            std::vector<Adyacente> l = adyacentes[i];
            if(l.empty())
                res << " sin adyacentes ";
            else
                res << " con adyacentes: ";
            for (auto ady : l)
                res << ady.dest << "(" << ady.coste << ") ";
            res << "\n";
        }
        return res.str();
    }
};

using namespace std;

int main() {
    
    while(true) {

        int n_nodos;
        cin >> n_nodos;
        if (n_nodos == 0){
            break;
        }

        Grafo problem(n_nodos, false);
        int n_edges;
        cin >> n_edges;
        int origin, dest;

        for(int i=0;i<n_edges;i++){
            cin >> origin >> dest;
            problem.insertarArista(origin,dest,0);
        }
        
        vector<int> next_to_visit;
        set<int> seen;
        bool bicolorable = true;
        int actual_node = 0;
        int color_nodes[n_nodos] = {};
        color_nodes[actual_node] = color_black;

        while (seen.size() < n_nodos || next_to_visit.size() > 0) {

            if (seen.find(actual_node) == seen.end()) {

                seen.insert(actual_node);

                int actual_color = color_nodes[actual_node];
                int neighbour_color;

                if (actual_color == color_black) neighbour_color = color_red;
                else neighbour_color = color_black;

                for (Adyacente ady : problem.adyacentes[actual_node]) {

                    if (seen.find(ady.dest) == seen.end()) next_to_visit.push_back(ady.dest);

                    if (color_nodes[ady.dest] == actual_color) {
                        
                        bicolorable = false;
                        break;
                        
                    } else {

                        color_nodes[ady.dest] = neighbour_color;
                    
                    }
                    
                }

                if(!bicolorable) break;

            }
            
            if(next_to_visit.size() > 0){
                actual_node = next_to_visit[0];
                next_to_visit.erase(next_to_visit.begin());
            }

        }

        if(seen.size() < n_nodos) {
            string aux = problem.toString();
        }

        if(bicolorable) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";

    }
    
}
