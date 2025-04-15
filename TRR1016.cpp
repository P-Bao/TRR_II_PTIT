#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

void solveType1(){
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> vertex(n + 1, {0, 0});
    int u, v;
    while(m--){
        cin >> u >> v;
        vertex[u].second++;
        vertex[v].first++;
    }

    for(int i = 1; i <= n; ++i) cout << vertex[i].first << " " << vertex[i].second << endl;
}

void solveType2(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    int u, v;
    while(m--){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << n << endl;
    for(int i = 1; i <= n; ++i){
        cout << adj[i].size() << " ";
        for(int u : adj[i]) cout << u << " ";
        cout << endl;
    }
}

void solve(){
    int type;
    cin >> type;

    if(type == 1) solveType1();
    else solveType2();
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    solve();

    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
