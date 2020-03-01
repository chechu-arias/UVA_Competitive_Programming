#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

class Adyacente {

public:

    int dest;

    Adyacente(int dest) {
        this->dest = dest;
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

    void insertarArista(int origen, int dest) {
        
        Adyacente ady_origen(dest);
        Adyacente ady_dest(origen);
        
        adyacentes[origen].push_back(ady_origen);
        adyacentes[dest].push_back(ady_dest);

        gradosEntrada[origen]++;
        gradosEntrada[dest]++;

        numAristas++;
        numAristas++;
    
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

        for (unsigned int i = 0; i < adyacentes[dest].size(); i++) {
            Adyacente ady = adyacentes[dest][i];
            if (ady.dest == origen) {
                adyacentes[dest].erase(adyacentes[dest].begin() + i);
                gradosEntrada[dest]--;
                numAristas--;
            }
        }

    }

};

int main() {

    int count_cases = 0;

    while (true) {
        
        count_cases++;

        int n_citys;
        std::cin >> n_citys;

        if (n_citys == 0) break;

        if(count_cases > 1) std::cout << "\n";

        int cont = 0;
        for(int i = 0; i < n_citys; i++) {
            std::string city;
            std::cin >> city;
        }
        
        Grafo problem(n_citys);

        int n_connections;
        std::cin >> n_connections;

        int cont_citys = 0;
        std::set<std::string> citys_actually_connected;
        std::map <std::string, int> conversion;
        std::string citynames[n_citys];

        for(int i = 0; i < n_connections; i++) {

            std::string origen, dest;
            std::cin >> origen >> dest;
            
            if (citys_actually_connected.find(origen) == citys_actually_connected.end()) {
                citynames[cont_citys] = origen;
                conversion[origen] = cont_citys++;
                citys_actually_connected.insert(origen);
            }

            if (citys_actually_connected.find(dest) == citys_actually_connected.end()) {
                citynames[cont_citys] = dest;
                conversion[dest] = cont_citys++;
                citys_actually_connected.insert(dest);
            }

            problem.insertarArista(conversion[origen], conversion[dest]);
        }

        //Getting the different subgraphs
        int cont_group = 0;
        int cont_in_group = 0;
        int size_of_groups[cont_citys];
        int groups[cont_citys][cont_citys];
        std::vector<int> actualgroup;

        std::set <int> seen;

        for (int i = 0; i < cont_citys; i++) {

            if ( seen.find(i) == seen.end() ) {

                actualgroup.push_back(i);

                while (actualgroup.size() > 0) {

                    if (seen.find(actualgroup.at(0)) == seen.end()) {

                        seen.insert(actualgroup.at(0));
                        groups[cont_group][cont_in_group++] = actualgroup.at(0);

                        for (auto ady : problem.adyacentes[actualgroup.at(0)]) {
                            if(seen.find(ady.dest) == seen.end()) {
                                actualgroup.push_back(ady.dest);
                            }
                        }

                    }

                    actualgroup.erase(actualgroup.begin());

                }

                size_of_groups[cont_group] = cont_in_group;
                cont_group++;
                cont_in_group = 0;

            }
        }



        std::vector<int> solutions;

        for (int gr = 0; gr < cont_group; gr++) {

            if(!size_of_groups[gr]) break;
            if(size_of_groups[gr] < 3) continue;

            for(int i = 0; i < size_of_groups[gr]; i++) {

                int elem = groups[gr][i];

                // Deleting the node in the subgraph
                std::vector<int> deleted_conexions;

                while(problem.adyacentes[elem].size() > 0) {
                    Adyacente ady = problem.adyacentes[elem].at(0);
                    problem.eliminarArista(elem, ady.dest);
                    deleted_conexions.push_back(ady.dest);
                }


                // Seeing if the subgraph is connected without the node
                int aux = groups[gr][0];
                if(!i)
                    aux = groups[gr][1];

                std::set<int> seen;
                std::vector<int> toexplore;
                toexplore.push_back(aux);
                
                while(toexplore.size() > 0) {

                    toexplore.erase(toexplore.begin());
                    
                    if (seen.find(aux) == seen.end()) {

                        seen.insert(aux);
                    
                        for (auto ady : problem.adyacentes[aux]) {
                            if (seen.find(ady.dest) == seen.end()) {
                                toexplore.push_back(ady.dest);
                            }
                            
                            if(seen.size() == cont_citys-1) break;
                        }

                        if(seen.size() == cont_citys-1) break;

                    }

                    if(toexplore.size() == 0) break;
                    aux = toexplore.at(0);

                }

                if(seen.size() < size_of_groups[gr]-1) {
                    solutions.push_back(elem);
                }


                // Undoing changes and adding again the node
                for (auto v : deleted_conexions) {
                    problem.insertarArista(elem, v);
                }

            }

        }
           

        std::cout << "City map #" << count_cases << ": " << solutions.size() << " camera(s) found\n";
        std::vector<std::string> names_of_solutions;
        if(solutions.size() > 0) {
            for (auto sol : solutions) {
                names_of_solutions.push_back(citynames[sol]);
            }
            
            std::sort(names_of_solutions.begin(), names_of_solutions.end());

            for (auto elem : names_of_solutions) {
                std::cout << elem << "\n";
            }
        }

    }

}