#include <bits/stdc++.h>

#define INF 1000000000

using namespace std;

void solve(){
    int n, start, end;
    cin >> n >> start >> end;

    int matrix[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] > 50) matrix[i][j] = 0; 
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int dist[n + 1], par[n + 1];
    for(int i = 1; i <= n; ++i) {
        dist[i] = INF;
        par[i] = -1;
    }

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int u = pq.top().second, du = pq.top().first;
        pq.pop();

        if(du > dist[u]) continue;

        for(int v = 1; v <= n; ++v) 
            if(matrix[u][v] != 0) {
                int newDist = dist[u] + matrix[u][v];
                if(newDist < dist[v]) {
                    dist[v] = newDist;
                    par[v] = u;
                    pq.push({newDist, v});
                }
            }
    }

    if(dist[end] == INF) {
        cout << "0" << endl;
        return;
    }

    vector<int> path;
    for(int u = end; u != -1; u = par[u]) path.push_back(u);
    reverse(path.begin(), path.end());

    cout << dist[end] << endl;
    for(int u : path) cout << u << " ";
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    solve();

    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
