#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> graph(1005);

// Tìm chu trình Euler
vector<int> EulerCycle(int start){
    vector<int> cycle;
    stack<int> st;
    st.push(start);

    while(!st.empty()){
        int u = st.top();

        bool hasEdge = false;
        for(int v = 1; v <= n; ++v){
            if(graph[u][v]){
                hasEdge = true;
                st.push(v);
                graph[u][v] = graph[v][u] = 0;          
            }
        }

        if(!hasEdge){
            cycle.push_back(u);
            st.pop();
        }
    }

    reverse(cycle.begin(), cycle.end());
    return cycle;
}

void solveType1(){
    int m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) graph[i].resize(n + 1, 0);
    int u, v;
    while(m--){
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    int odd = 0;
    for(int i = 1; i <= n; ++i){
        int deg = accumulate(graph[i].begin() + 1, graph[i].end(), 0);
        if(deg % 2) odd++;
    }

    if(odd == 0) cout << 1 << endl;
    else if(odd == 2) cout << 2 << endl;
    else cout << 0 << endl;
}

void solveType2(){
    int m, start;
    cin >> n >> m >> start;

    for(int i = 1; i <= n; ++i) graph[i].resize(n + 1, 0);
    int u, v;
    while(m--){
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    vector<int> eulerCycle = EulerCycle(start);
    for(int u : eulerCycle) cout << u << " ";
    cout << endl;
}

void solve(){
    int type;
    cin >> type;
    
    if(type == 1) solveType1();
    else solveType2();
}

int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    // int t;
    // cin >> t;
    // while(t--){
        solve();
    //}
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}