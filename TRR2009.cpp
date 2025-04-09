#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>>adj(1005);
vector<int> visited(1005);

vector<int> FindComponentUsingDFS(int start){
    vector<int> component;
    stack<int> s;

    s.push(start);
    visited[start] = true;
    component.push_back(start);

    while(!s.empty()){
        int u = s.top();
        s.pop();

        for(int v : adj[u]){
            if(!visited[v]){
                component.push_back(v);
                visited[v] = true;
                s.push(v);
            }
        }
    }

    sort(component.begin(), component.end());
    return component;
}

void solve(){
    int n, x;
    cin >> n;

    visited.resize(n + 1, false);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> x;
            if(x == 1){
                adj[i].push_back(j);
                //adj[j].push_back(i);
            }
        }
        
    vector<vector<int>> res;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            res.push_back(FindComponentUsingDFS(i));
        }
    }

    cout << res.size() << endl;
    for(auto &component : res){
        for(int v : component) cout << v << " ";
        cout << endl;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    solve();
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
