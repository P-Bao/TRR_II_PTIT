#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> HamiltonCycle;
vector<vector<int>> graph;

void findHamiltonianCycle(int currentVertex, vector<bool>& visited, vector<int>& path, int startVertex) {
    // Nếu đã thăm tất cả các đỉnh
    if (path.size() == n) {
        // Kiểm tra có đường về đỉnh bắt đầu không
        if (graph[currentVertex][startVertex] == 1) {
            path.push_back(startVertex);
            HamiltonCycle.push_back(path);
            path.pop_back();
        }
        return;
    }

    // Lặp qua tất cả các đỉnh
    for (int vertex = 1; vertex <= n; vertex++) {
        if (graph[currentVertex][vertex] == 1 && !visited[vertex]) {
            visited[vertex] = true; 
            path.push_back(vertex);  

            findHamiltonianCycle(vertex, visited, path, startVertex);

            path.pop_back();
            visited[vertex] = false; 
        }
    }
}

void hamiltonianCycle(int startVertex) {
    vector<bool> visited(n + 1, false);
    vector<int> path;

    visited[startVertex] = true;
    path.push_back(startVertex);

    findHamiltonianCycle(startVertex, visited, path, startVertex);
}

void solve(){
    int m;
    cin >> n >> m;

    graph.assign(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> graph[i][j];
        
    hamiltonianCycle(m);
    cout << HamiltonCycle.size() << endl;
    for(auto path : HamiltonCycle){
        for(int u : path) cout << u << " ";
        cout << endl;
    }
}

int main() {
    solve();
    
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
