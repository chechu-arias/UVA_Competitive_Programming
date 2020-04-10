#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int id;
    int time;
    int penalty;
    float ratio;
} job;


bool mycomp (job const& j1, job const& j2) {

    return ((j1.ratio > j2.ratio) || (j1.ratio == j2.ratio && j1.id < j2.id));

}


int main() {

    int n_cases;
    cin >> n_cases;

    while(n_cases--) {

        int n_tasks;
        cin >> n_tasks;
        job data[n_tasks];
        for (int i = 0; i < n_tasks; i++) {
            int t, p;
            cin >> t >> p;
            job aux;
            aux.id = i+1;
            aux.time = t;
            aux.penalty = p;
            aux.ratio = (float)p/t;
            data[i] = aux;
        }

        sort(&data[0], &data[n_tasks], &mycomp);//[] (const job &j1, const job &j2) { return ((j1.ratio > j2.ratio) || (j1.ratio == j2.ratio && j1.penalty < j2.penalty)); } );

        //for(auto i : data) cout << i.id << " " << i.time << " " << i.penalty << " " << i.ratio << "\n"; 
        for(int i = 0; i < n_tasks-1; i++) cout << data[i].id << " ";
        cout << data[n_tasks-1].id << "\n";

        if(n_cases > 0) cout << "\n";
    }

}