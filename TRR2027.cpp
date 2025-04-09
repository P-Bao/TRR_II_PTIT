#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
 
using namespace std;
 
const int maxN = 1e5;
 
int num[maxN];                                  // thứ tự duyệt của mỗi đỉnh
int low[maxN];                                  // low[u] là thứ tự thăm của đỉnh có thứ tự thăm sớm nhất nằm trong cây con gốc u
                                                 // hoặc kề cạnh với  đỉnh bất kì nằm trong cây con gốc u.
int tail[maxN];                                 // thời điểm duyệt xong của đỉnh
vector<int> g[maxN];

vector<pair<int, int>> bridges;                  
 
int timeDFS = 0;                                 // thứ tự duyệt DFS
void dfs(int u , int pre){                       // u: đỉnh đang xét, pre: đỉnh trước u
    num[u] = low[u] = ++timeDFS;
    for(int v : g[u]){
        if(v == pre) continue;

        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
 
            if(low[v] == num[v]) bridges.push_back({u, v}); 
        }
        else low[u] = min(low[u], num[v]);
    }
    tail[u] = timeDFS;
}
 
int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    int n;  cin >> n;                  
     
    int x;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
           cin >> x;
           if(x) g[i].push_back(j);
        }
     
    for(int i = 1; i <= n; ++i)
        if(!num[i]) dfs(i, i);

    sort(bridges.begin(), bridges.end()); 
    bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());

    cout << bridges.size() << endl;
    for(auto p : bridges) cout << p.first << " " << p.second << endl; 
 
     return 0;
 }
