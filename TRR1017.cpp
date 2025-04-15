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

    vector<pair<int, int>> edges(m);
    int u, v;
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        edges[i] = {u, v};
    }
    
    vector<vector<int>> arr(n + 1, vector<int>(m, 0));
    for(int i = 0; i < m; ++i){arr[edges[i].first][i] = 1;
        arr[edges[i].second][i] = -1;
    }
    
    cout << n << " " << m << endl;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < m; ++j) cout << arr[i][j] << " ";
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
