#include <vector>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <utility>
#include <climits>
#include <cmath>

class Adyacente {
public:
    int hourOut, hourIn, dest;
    Adyacente(int dest, int hourOut, int hourIn) {
        this->dest = dest;
        this->hourOut = hourOut;
        this->hourIn = hourIn;
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

    void insertarArista(int origen, int dest, int hourOut, int hourIn) {
        Adyacente ady(dest, hourOut, hourIn);
        adyacentes[origen].push_back(ady);
        gradosEntrada[origen]++;
        numAristas++;
    }

    bool existeArista(int origen, int dest) {
        for (auto ady : adyacentes[origen]) {
            if (ady.dest == dest)
                return true;
        }
        return false;
    }

    std::string toString() {
        
        std::stringstream res;
        for (int i = 0; i < numNodos; i++) {
            
            res << "Vertice: " << i;
            
            std::vector<Adyacente> l = adyacentes[i];
            if(l.empty()) {
                res << " sin adyacentes ";
            } else {
                res << " con adyacentes: ";
            }

            for(auto ady : l) {
                res << ady.dest << " (" << ady.hourOut << ", " << ady.hourIn << ") ";
            }
            res << "\n";

        }

        return res.str();

    }
};

 

int main() {

    int n_cases;
    std::cin >> n_cases;
    
    for (int c = 1; c <= n_cases; c++) {

        int n_conex;
        std::cin >> n_conex;

        std::map<std::string, int> map_citys;

        std::string orig, dest;
        int hourOut, hoursOfTravel;
        Grafo problem(105);

        int cont_citys = 0;

        for (int i = 1; i <= n_conex; i++) {

            std::cin >> orig >> dest >> hourOut >> hoursOfTravel;

            if ( (hourOut > 17 && hourOut+hoursOfTravel <= 30) || (hourOut+hoursOfTravel < 7) ) {
                
                if (map_citys.find(orig) == map_citys.end()) {
                    map_citys.insert( std::pair<std::string, int>(orig, cont_citys++) );
                }

                if (map_citys.find(dest) == map_citys.end()) {
                    map_citys.insert( std::pair<std::string, int>(dest, cont_citys++) );
                }

                int hourIn = 0;
                int aux = hourOut+hoursOfTravel;
                if (aux < 7 || aux < 24) {
                    hourIn = aux;
                } else {
                    hourIn = aux - 24;
                }

                if (hourOut < 7) hourOut += 24;
                hourIn = hourOut+hoursOfTravel;
                
                problem.insertarArista(map_citys[orig], map_citys[dest], hourOut, hourIn);

            }

        }

        std::string start, target;
        std::cin >> start >> target;

        if (start == target) {
            
            std::cout << "Test Case " << c << ".\n";
            std::cout << "Vladimir needs 0 litre(s) of blood.\n";

        } else if (map_citys.find(start) == map_citys.end() || map_citys.find(target) == map_citys.end()) {
            
            std::cout << "Test Case " << c << ".\n";
            std::cout << "There is no route Vladimir can take.\n";
        
        } else {

            std::pair<int,int> travels[cont_citys];

            std::vector<std::pair<int,int>> iter;
            iter.push_back( std::pair<int,int>(map_citys[start], 17) );

            while(iter.size() > 0) {

                std::pair<int,int>actual = iter[0];

                int orig = actual.first;
                int origBlood = travels[orig].first;
                int orighOut = travels[orig].second;

                iter.erase(iter.begin());

                for (auto ady : problem.adyacentes[orig]) {
                    
                    int dest = ady.dest;
                    int destBlood = travels[dest].first;
                    int destHour = travels[dest].second;

                    // Initialization case
                    if (destBlood == 0 && destHour == 0) {

                        // Direct trip
                        if (orighOut <= ady.hourOut) {
                            
                            travels[dest] = std::pair<int, int>(origBlood, ady.hourIn);

                        // Has to take it the next day
                        } else {

                            travels[dest] = std::pair<int, int>(origBlood+1, ady.hourIn);

                        }

                        iter.push_back( std::pair<int,int>(dest, ady.hourIn) );
                    
                    // Origen needs less blood than where i am
                    } else if ( origBlood < destBlood ) {

                        // Direct trip
                        if (orighOut <= ady.hourOut) {

                            travels[dest] = std::pair<int, int>(origBlood, ady.hourIn);
                            iter.push_back( std::pair<int,int>(dest, ady.hourIn) );

                        // Has to take it the next day
                        } else if (origBlood+1 < destBlood || (origBlood+1 == destBlood && ady.hourIn < destHour) ) {

                            travels[dest] = std::pair<int, int>(origBlood+1, ady.hourIn);
                            iter.push_back( std::pair<int,int>(dest, ady.hourIn) );

                        }

                    // Origen needs same blood but can take a direct trip and arrive before what we had
                    } else if (origBlood == destBlood && orighOut <= ady.hourOut && ady.hourIn < destHour) {

                        travels[dest] = std::pair<int, int>(destBlood, ady.hourIn);
                        iter.push_back( std::pair<int,int>(dest, ady.hourIn) );

                    }

                }

            }

            std::cout << "Test Case " << c << ".\n";
            int resBlood = travels[map_citys[target]].first;

            if (!resBlood && !travels[map_citys[target]].second) {

                std::cout << "There is no route Vladimir can take.\n";

            } else {

                std::cout << "Vladimir needs " << resBlood << " litre(s) of blood.\n";

            }

        }

    }

}