#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int minCost = INT_MAX;
vector<int> res;
vector<vector<int>> graph;

int totalCost(vector<int>& path){
    int cost = 0;
    for(int i = 0; i < path.size() - 1; ++i){
        cost += graph[path[i]][path[i + 1]];
    }
    return cost;
}

void findHamiltonianCycle(int currentVertex, vector<bool>& visited, vector<int>& path, int startVertex) {
    // Nếu đã thăm tất cả các đỉnh
    if (path.size() == n) {
        // Kiểm tra có đường về đỉnh bắt đầu không
        if (graph[currentVertex][startVertex] > 0 && graph[currentVertex][startVertex] <= 50) {
            path.push_back(startVertex);
            int cost = totalCost(path);
            
            if (cost < minCost) {
                minCost = cost;
                res = path;
            }

            path.pop_back();
        }
        return;
    }

    // Lặp qua tất cả các đỉnh
    for (int vertex = 1; vertex <= n; vertex++) {
        if (graph[currentVertex][vertex] > 0 && graph[currentVertex][vertex] <= 50 && !visited[vertex]) {
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
    
    if(minCost == INT_MAX) {
        cout << 0 << endl;
        return;
    }
    cout << minCost << endl;
    for(int u : res) cout << u << " ";
}

int main() {
    solve();
    
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
