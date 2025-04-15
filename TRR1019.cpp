#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

void solveType1(){
    int n;
    cin >> n;
    
    vector<pair<int, int>> vertex(n + 1, {0, 0});
    int u, k;
    for(int i = 1; i <= n; ++i){
        cin >> k;
        while(k--){
            cin >> u;
            vertex[i].second++;
            vertex[u].first++;
        }
    }

    for(int i = 1; i <= n; ++i) cout << vertex[i].first << " " << vertex[i].second << endl;
}

void solveType2(){
    int n;
    cin >> n;

    vector<pair<int, int>> edges;

    int u, k;
    for(int i = 1; i <= n; ++i){
        cin >> k;
        while(k--){
            cin >> u;
            edges.push_back({i, u});
        }
    }

    cout << n << " " << edges.size() << endl;
    for(const auto& [u, v] : edges) cout << u << " " << v << endl;
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
