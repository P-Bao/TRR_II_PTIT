#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (graph[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

bool isConnected() {
    visited.assign(n + 1, false);

    int start = -1;
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += graph[i][j];
        if (deg > 0) {
            start = i;
            break;
        }
    }

    if (start == -1) return true; // Không có cạnh nào, coi là liên thông

    dfs(start);

    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += graph[i][j];
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
                graph[u][v] = graph[v][u] = 0; // Vì đồ thị vô hướng
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

    if (!isConnected()) {
        cout << 0 << endl;
        return;
    }

    int odd = 0;
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += graph[i][j];
        if (deg % 2 != 0) ++odd;
    }

    if (odd == 0) cout << 1 << endl;         // Euler cycle
    else if (odd == 2) cout << 2 << endl;    // Euler path (nửa Euler)
    else cout << 0 << endl;                  // Không phải Euler
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
