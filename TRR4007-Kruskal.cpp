#include <bits/stdc++.h>

#define INF 1000000000

using namespace std;

class DSU {
    private:
        vector<int> par;
    public:
        DSU(int n) {
            par.resize(n + 1);
            iota(par.begin(), par.end(), 0);
        }

        int find(int x) {
            if(par[x] == x) return x;
            return par[x] = find(par[x]);
        }

        bool unionSet(int x, int y) {
            x = find(x);
            y = find(y);

            if(x == y) return false; 
            
            par[x] = y;
            return true;
        }
};

void solve(){
    int n, m;
    cin >> n >> m;

    
    vector<pair<int, pair<int, int>>> edges;
    int u, v, w;

    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    DSU dsu(n);
    vector<pair<pair<int, int>, int>> mstEdges;

    for(auto edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(dsu.unionSet(u, v)) {
            cost += weight;
            mstEdges.push_back({{u, v}, weight});
        }
    }

    cout << cost << endl;
    for(auto edge : mstEdges) {
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    solve();

    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
