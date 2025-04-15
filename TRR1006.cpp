#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int n;
int graph[105][105];

void solveType1(){
    int m;
    cin >> n >> m;

    int u, v;
    for(int i = 1; i <= m; ++i){
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    for(int i = 1; i <= n; ++i)
        cout << accumulate(graph[i] + 1, graph[i] + n + 1, 0) << " ";
}

void solveType2(){
    int m;
    cin >> n >> m;
    
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    
    int arr[n + 1][m];
    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < m; ++i)
        arr[edges[i].first][i] = arr[edges[i].second][i] = 1;
    
    cout << n << " " << m << endl;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < m; ++j) cout << arr[i][j] << " ";
        cout << endl;
    }
}

void solve(){
    int type, m;
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
