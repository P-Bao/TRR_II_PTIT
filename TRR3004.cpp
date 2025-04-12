#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u, vector<vector<int>>& g) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) 
        if (g[u][v] && !visited[v]) 
            dfs(v, g);
}

bool isStronglyConnected() {
    visited.assign(n + 1, false);
    int start = -1;

    for (int i = 1; i <= n; ++i) {
        int out_deg = 0;
        for (int j = 1; j <= n; ++j)
            out_deg += graph[i][j];
        if (out_deg > 0) {
            start = i;
            break;
        }
    }

    if (start == -1) return true; // Không có cạnh nào, coi là liên thông mạnh

    dfs(start, graph);
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += graph[i][j] + graph[j][i]; // có cạnh vào hoặc ra
        if (deg > 0 && !visited[i]) return false;
    }

    // Đảo chiều đồ thị
    vector<vector<int>> revGraph(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (graph[i][j])
                revGraph[j][i] = graph[i][j];

    // DFS trên đồ thị đảo
    visited.assign(n + 1, false);
    dfs(start, revGraph);
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += graph[i][j] + graph[j][i];
        if (deg > 0 && !visited[i]) return false;
    }

    return true;
}

vector<int> EulerCycle(int start) {
    vector<int> cycle;
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        bool hasEdge = false;

        for (int v = 1; v <= n; ++v) {
            if (graph[u][v]) {
                hasEdge = true;
                st.push(v);
                graph[u][v] = 0;
                break;
            }
        }

        if (!hasEdge) {
            cycle.push_back(u);
            st.pop();
        }
    }

    reverse(cycle.begin(), cycle.end());
    return cycle;
}
void solveType1() {
    cin >> n;
    graph.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> graph[i][j];

    if (!isStronglyConnected()) {
        cout << 0 << endl;
        return;
    }

    int start = 0, end = 0;

    for (int i = 1; i <= n; ++i) {
        int out_deg = 0, in_deg = 0;
        for (int j = 1; j <= n; ++j) {
            out_deg += graph[i][j];
            in_deg += graph[j][i];
        }

        if (out_deg == in_deg + 1) ++start;
        else if (in_deg == out_deg + 1) ++end;
        else if (in_deg != out_deg) {
            cout << 0 << endl;
            return;
        }
    }

    if (start == 0 && end == 0) cout << 1 << endl;       // Euler cycle
    else if (start == 1 && end == 1) cout << 2 << endl;  // Euler path
    else cout << 0 << endl;                              // Not Euler
}

void solveType2() {
    int start;
    cin >> n >> start;
    graph.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> graph[i][j];

    vector<int> cycle = EulerCycle(start);
    for (int u : cycle) cout << u << " ";
    cout << endl;
}

void solve() {
    int t;
    cin >> t;

    if (t == 1) solveType1();
    else if (t == 2) solveType2();
}

int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    solve();

    return 0;
}
