#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define INF 1000000000

using namespace std;

void solve(){
    int n, start, end;
    cin >> n >> start >> end;

    int graph[n + 1][n + 1];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) { 
            cin >> graph[i][j];
            if(graph[i][j] == 0 || graph[i][j] == 10000) graph[i][j] = INF;
        }
    
    int dist[n + 1];
    int par[n + 1];

    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        par[i] = -1;
    }

    dist[start] = 0;
    for(int i = 1; i < n; i++) 
        for(int u = 1; u <= n; u++) 
            for(int v = 1; v <= n; v++) 
                if(graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    par[v] = u;
                }
    for(int i = 1; i <= n; i++) {
        for(int u = 1; u <= n; u++) {
            for(int v = 1; v <= n; v++) {
                if(graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = -INF;
                    par[v] = u;
                }
            }
        }
    }
    
    if(dist[end] == INF) {
        cout << "0\n";
        return;
    }
    if(dist[end] == -INF) {
        cout << "-1\n";
        return;
    }

    vector<int> path;
    for(int u = end; u != -1; u = par[u]) path.push_back(u);
    reverse(path.begin(), path.end());

    cout << dist[end] << endl;
    for(int v : path) cout << v << " ";
}

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    solve();
    
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}