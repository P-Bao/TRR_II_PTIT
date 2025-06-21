#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define INF 1000000000

using namespace std;

int n;
int graph[105][105];

void PrimMST(int start) {
    vector<int> par(n + 1, -1);
    vector<int> dist(n + 1, INF);
    vector<bool> inMST(n + 1, false);
    
    dist[start] = 0;
    inMST[start] = true;

    int totalWeight = 0;
    vector<tuple<int, int, int>> mstEdges;

    while(mstEdges.size() < n - 1) {
        int u = -1, v = -1, minDist = INF;
        for(int i = 1; i <= n; ++i)
            if(inMST[i]){
                for(int j = 1; j <= n; ++j)
                    if(!inMST[j] && graph[i][j] != 0 && graph[i][j] < minDist) {
                        minDist = graph[i][j];
                        u = j;
                        v = i;
                    }
            }
        
        if(u == -1 || v == -1) {
            cout << 0;
            return;
        }

        mstEdges.push_back(make_tuple(v, u, graph[v][u]));
        totalWeight += graph[v][u];
        inMST[u] = true;
    }

    cout << totalWeight << endl;
    for (const auto& edge : mstEdges) {
        int u = get<0>(edge), v = get<1>(edge);
        if (u > v) swap(u, v);
        cout << u << " " << v << " " << get<2>(edge) << endl;
        // cout << get<0>(edge) << " " << get<1>(edge) << " " << get<2>(edge) << endl;
    }
}

void solve() {
    int start;
    cin >> n >> start;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 10000) graph[i][j] = 0; 
        }
    
    PrimMST(start);
}

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    solve();
    
    return 0;
}