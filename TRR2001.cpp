#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Matrix {
    int n;
    vector<vector<int>> arr;

    Matrix(int n): n(n), arr(n + 1, vector<int>(n + 1, 0)) {}
};

Matrix operator* (const Matrix &A, const Matrix &B){
    int n = A.n;
    Matrix res(A.n);
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
                res.arr[i][j] += A.arr[i][k] * B.arr[k][j];
    
    return res;
}

void solveType1(){
    int n, start, end;
    cin >> n >> start >> end;
    Matrix A(n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> A.arr[i][j];
    A = A * A;
    cout << A.arr[start][end] << endl;
}

vector<vector<int>>adj(1005);
vector<bool> visited(1005);
vector<int> trace;

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v]){
            dfs(v);
            trace[v] = u;
        }
}

void findPath(int start, int end) {
    trace.resize(1005, -1);
    dfs(start);

    if(!visited[end]){
        cout << 0 << endl;
        return;
    }

    vector<int> path;
    for(int v = end; v != -1; v = trace[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    for(int u : path) cout << u << " ";
    cout << endl;
}

void solveType2(){
    int n, start, end;
    cin >> n >> start >> end;

    int x;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> x;
            if(x == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        
    findPath(start, end);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    int type;
    cin >> type;
    if(type == 1) solveType1();
    else solveType2();
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
