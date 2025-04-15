#include <iostream>
#include <numeric>

using namespace std;

int n;
int graph[105][105];

void solveType1(){
    for(int i = 1; i <= n; ++i){
        int deg = 0;
        for(int j = 1; j <= n; ++j)
            deg += (graph[i][j] != 0 && graph[i][j] != 10000);
        cout << deg << " ";
    }
}

void solveType2(){
    int edges = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            edges += (graph[i][j] != 0 && graph[i][j] != 10000);
    cout << n << " " << edges << endl;

    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(graph[i][j] != 0 && graph[i][j] != 10000)
                cout << i << " " << j << " " << graph[i][j] << endl;
}

void solve(){
    int type;
    cin >> type >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> graph[i][j];
    
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
