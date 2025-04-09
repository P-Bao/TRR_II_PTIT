#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

int n, m;
vector<vector<int>>adj(1005);
vector<pair<int, int>> edges;
bitset<1005> visited;

void bfs(int u){
    queue<int> q;

    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u])
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
    }
}

vector<pair<int, int>> findBridges(){
    vector<pair<int, int>> bridges;
    for(pair<int, int> edge : edges){
        int u = edge.first, v = edge.second;

        // Erase edge (u, v)
        adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
        adj[v].erase(find(adj[v].begin(), adj[v].end(), u));

        visited.reset();
        bfs(u);             // Hoặc dfs(u);
        if(!visited[v]) bridges.push_back(edge);

        // Restore edge (u, v)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return bridges;
}

void solve(){
    int x;
    cin >> n;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> x;
            if(x == 1){
                adj[i].push_back(j);

                if(i < j) edges.push_back({i, j});
            }
        }
    
    vector<pair<int, int>> bridges = findBridges();
    sort(bridges.begin(), bridges.end());
    bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());

    cout << bridges.size() << endl;
    for(pair<int, int> edge : bridges) cout << edge.first << " " << edge.second << endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    solve();
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
