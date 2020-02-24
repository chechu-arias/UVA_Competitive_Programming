#include <vector>
#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
#include <utility>
#include <climits>
#include <cmath>

typedef std::pair<int, int> ii;
#define MAX_VALUE 1e9

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
    int numNodos, numAristas;
    std::vector<int> gradosEntrada;
    std::vector<std::vector <Adyacente> > adyacentes;

    Grafo(int numNodos) {
        this->numNodos = numNodos;
        this->numAristas = 0;
        gradosEntrada.resize(numNodos, 0);
        adyacentes.resize(numNodos);
    }

    void insertarArista(int origen, int dest, int coste) {
        Adyacente adyorig(dest, coste);
        Adyacente adydest(origen, coste);
        adyacentes[origen].push_back(adyorig);
        adyacentes[dest].push_back(adydest);
        gradosEntrada[origen]++;
        gradosEntrada[dest]++;
        numAristas++;
        numAristas++;
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

};

int getBestRoute(int origen, int dest, Grafo graph) {
    
    std::vector<int> capacidad(graph.numNodos, 0);
    std::set<int> prev;
    std::priority_queue< ii, std::vector<ii>, std::less<ii>> caminos;
    caminos.push(ii(0, origen));

    while(!caminos.empty()) {

        ii actual = caminos.top(); caminos.pop();

        if (prev.find(actual.second) == prev.end()) {

            for (auto ady : graph.adyacentes[actual.second]) {

                if (prev.find(ady.dest) == prev.end()) {

                    if(actual.second == origen) {

                        capacidad[ady.dest] = ady.coste;

                    } else if(capacidad[ady.dest] == 0) {
                        
                        if(capacidad[actual.second] < ady.coste) {
                            capacidad[ady.dest] = capacidad[actual.second];
                        } else {
                            capacidad[ady.dest] = ady.coste;
                        }

                    } else if (capacidad[actual.second] > capacidad[ady.dest]) {

                        if(capacidad[actual.second] < ady.coste) {
                            capacidad[ady.dest] = capacidad[actual.second];
                        } else if (ady.coste > capacidad[ady.dest]) {
                            capacidad[ady.dest] = ady.coste;
                        }

                    }

                    if (prev.find(ady.dest) == prev.end())
                        caminos.push(ii(capacidad[ady.dest], ady.dest));
                
                }
                
            }

        }

        prev.insert(actual.second);

    }

    return capacidad[dest]-1;

}



int main() {

    int cont = 0;
    while(true) {
        cont++;
        int N, R;
        std::cin >> N >> R;
        if (N == 0 && R == 0) break;

        Grafo problem(N+1);
        for(int i = 0; i < R; i++) {
            int origen, dest, coste;
            std::cin >> origen >> dest >> coste;
            problem.insertarArista(origen, dest, coste); 
        }
        int S, D, T;
        std::cin >> S >> D >> T;
        int res = getBestRoute(S, D, problem);
        std::cout << "Scenario #" << cont << "\n";
        std::cout << "Minimum Number of Trips = " << ceil((double)T/res) << "\n\n";

    }
    
}