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
        for(int j = 1; j <= n; j++) 
            cin >> graph[i][j];
}

void solveType1(){
    for(int i = 1; i <= n; ++i)
        cout << accumulate(graph[i] + 1, graph[i] + n + 1, 0) << " ";
}

void solveType2() {
    vector<pair<int, int>> edges;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j) 
            if(graph[i][j]) edges.push_back({i, j});

    cout << n << " " << edges.size() << endl;
    for(auto &edge : edges) cout << edge.first << " " << edge.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    input();

    if(t == 1) solveType1();
    else solveType2();

    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}