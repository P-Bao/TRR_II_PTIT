#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <bitset>

using namespace std;

int graph[1005][1005];
bool visited[1005];
int n;
int tplt, cnt;
void DFS(int i) {
    visited[i] = 1;
    for(int j = 1; j <= n; j++)
    {
        if(graph[i][j] && !visited[j]) DFS(j);
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            cin >> graph[i][j];
        
    for(int i = 1; i <= n; i++)
        if(!visited[i]) {
            tplt++;
            DFS(i);
        }
    
    vector<int> res;
    for(int i = 1; i <= n; i++)
    {
        memset(visited,0,sizeof(visited));
        vector<int> v;
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j])
            {
                v.push_back(j);
                graph[i][j] = 0;
                graph[j][i] = 0;
            }
        }
        cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j] && j != i) 
            {
                cnt++;
                DFS(j);
            }
        }
        if(cnt > tplt) res.push_back(i);
        for(int x : v)
        {
            graph[i][x] = 1;
            graph[x][i] = 1;
        }
    }

    cout << res.size() << endl;
    for(int u : res) cout << u << " ";

    
    return 0;
}
