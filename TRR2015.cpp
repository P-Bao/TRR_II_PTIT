#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
vector<int> visited(1005);

void DFS(int u, vector<vector<int>>& graph){
    visited[u] = 1;

    for(int v : graph[u])
        if(!visited[v]) DFS(v, graph);
}

bool isStronglyConnected(vector<vector<int>>& graph){
    for (int i = 1; i <= n; ++i) {
        fill(visited.begin(), visited.end(), 0);
        DFS(i, graph);
        for (int j = 1; j <= n; ++j)
            if (!visited[j]) return false;
    }
    return true;
}

bool isWeaklyConnected(vector<vector<int>>& graph){
    fill(visited.begin(), visited.end(), 0);
    DFS(1, graph);

    for(int i = 1; i <= n; ++i)
        if(!visited[i]) return false;
    
    return true;
}

void solve(){
    int x;
    cin >> n;

    vector<vector<int>>directedGraph(n + 5), undirectedGraph(n + 5);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> x;
            if(x == 1){
                directedGraph[i].push_back(j);

                undirectedGraph[i].push_back(j);
                undirectedGraph[j].push_back(i);
            }
        }
        
    if(isStronglyConnected(directedGraph))
        cout << 1 << endl;
    else if(isWeaklyConnected(undirectedGraph))
        cout << 2 << endl;
    else 
        cout << 0 << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    
    solve();
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
