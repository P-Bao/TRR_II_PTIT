#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define INF 1000000000

using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;

void input() {
    cin >> n >> m;
    
    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
}
 
void solveType1() {
    int deg[n + 1];
    for(int i = 1; i <= n; i++) deg[i] = 0;
    
    for(auto &edge : edges) {
        deg[get<0>(edge)]++;
        deg[get<1>(edge)]++;
    }

    for(int i = 1; i <= n; i++) cout << deg[i] << " ";
}

void solveType2(){
    int graph[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = (i == j) ? 0 : 10000;
    
    for(auto &edge : edges) {
        int u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);
        graph[u][v] = graph[v][u] = w;
    }

    cout << n << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) cout << graph[i][j] << " ";
        cout << endl;
    }
}

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin >> t;
    
    input();

    if(t == 1) solveType1();
    else solveType2();
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}