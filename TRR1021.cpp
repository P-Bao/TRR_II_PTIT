#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define INF 1000000000

using namespace std;

int n;
int graph[105][105];

void input() {
    cin >> n;

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 0 && i == j) graph[i][j] = INF;
            if(graph[i][j] == 10000) graph[i][j] = INF;
        }
}
 
void solveType1() {
    int inDeg[n + 1], outDeg[n + 1];
    for(int i = 1; i <= n; ++i) inDeg[i] = outDeg[i] = 0;
    
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) 
            if(graph[i][j] != INF) {
                outDeg[i]++;
                inDeg[j]++;
            }
        
    for(int i = 1; i <= n; ++i) 
        cout << inDeg[i] << " " << outDeg[i] << endl;
}

void solveType2(){
    vector<tuple<int, int, int>> edges;

    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) 
            if(graph[i][j] != INF) edges.push_back({graph[i][j], i, j});
    
    cout << n << " " << edges.size() << endl;
    for(auto &edge : edges) 
        cout << get<1>(edge) << " " << get<2>(edge) << " " << get<0>(edge) << endl;
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