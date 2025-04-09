#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int>> graph(1005);

bool isEulerCycle(){
    for(int u = 1; u <= n; ++u){
        int deg = 0;
        for(int v = 1; v <= n; ++v){
            deg += graph[u][v];
        }
        if(deg % 2) return false;
    }
    return true;
}
pair<int, int> isHalfEulerCycle(){
    pair<int, int> res = {0, 0};
    int cnt = 0;
    for(int u = 1; u <= n; ++u){
        int deg = 0;
        for(int v = 1; v <= n; ++v){
            deg += graph[u][v];
        }
        if(deg % 2){ 
            ++cnt;
            if(cnt == 1) res.first = u;
            if(cnt == 2) res.second = u;
        }
    }

    if(cnt != 2) return make_pair(0, 0);
    return res;
}

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
                graph[u][v] = graph[v][u] = 0;          // Nếu là đồ thị có hướng thì chỉ cần xóa cạnh (u, v), không cần xóa cạnh (v, u)
                break;
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
    cin >> n;
    for(int i = 1; i <= n; ++i) graph[i].resize(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> graph[i][j];

    if(isEulerCycle()) cout << 1 << endl;
    else if(isHalfEulerCycle() != make_pair(0, 0)) cout << 2 << endl;
    else cout << 0 << endl;
}

void solveType2(){
    int start;
    cin >> n >> start;

    for(int i = 1; i <= n; ++i) graph[i].resize(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> graph[i][j];

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    // while(t--){
        solve();
    //}
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
