#include <iostream>
#include <numeric>

using namespace std;

int n;
int graph[105][105];

void solveType1(){
    for(int i = 1; i <= n; ++i)
        cout << accumulate(graph[i] + 1, graph[i] + n + 1, 0) << " ";
}

void solveType2(){
    int edges = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            edges += graph[i][j];
    cout << n << " " << edges << endl;

    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(graph[i][j] == 1)
                cout << i << " " << j << endl;
}

void solve(){
    int type;
    cin >> type >> n;

    int u, k;
    for(int i = 1; i <= n; ++i){
        cin >> k;
        for(int j = 1; j <= k; ++j){
            cin >> u;
            graph[i][u] = 1;
        }
    }

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
