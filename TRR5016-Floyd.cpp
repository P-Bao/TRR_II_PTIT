#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define INF 1000000000

using namespace std;

void solve(){
    int n;
    cin >> n;

    int graph[105][105];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 0 || graph[i][j] == 10000) graph[i][j] = INF;
        }

    int next[105][105];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            next[i][j] = (graph[i][j] != INF) ? j : -1;

    for(int k = 1; k <= n; k++) 
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++) 
                if(graph[i][k] != INF && graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next[i][j] = next[i][k];
                }
            
    
    int maxDist = -INF, start = -1, end = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(graph[i][j] > maxDist && graph[i][j] != INF) {
                maxDist = graph[i][j];
                start = i;
                end = j;
            }
        }
    }

    if(maxDist == -INF) {
        cout << 0 << endl;
        return;
    }

    vector<int> path;
    int cur = start;
    while(cur != end) {
        path.push_back(cur);
        cur = next[cur][end];
    }
    path.push_back(end);

    cout << start << " " << end << " " << maxDist << endl;
    for(int u : path) cout << u << " ";
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    solve();
    
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}