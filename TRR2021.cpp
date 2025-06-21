#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

int n;
int matrix[1005][1005];
bool visited[1005];

void dfs(int u, int del) {
	visited[u] = true;
	for(int v = 1; v <= n; v++) {
		if(matrix[u][v] && !visited[v] && v != del) {
			dfs(v, del);
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) 
			cin >> matrix[i][j];

	int cnt = 0;
	for(int j = 1; j <= n; ++j) visited[j] = false;
	for(int i = 1; i <= n; ++i)  
			if(!visited[i]) {
				cnt++;
				dfs(i, 0);
			}

	vector<int> cutVertex;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) visited[j] = false;

		int cnt1 = 0;
		for(int j = 1; j <= n; ++j) {
			if(!visited[j] && j != i) {
				cnt1++;
				dfs(j, i);
			}
		}
		if(cnt1 > cnt) cutVertex.push_back(i);
	}

	if(cutVertex.empty()) {
		cout << "0" << endl;
		return;
	}
	cout << cutVertex.size() << endl;
	for(int u : cutVertex) cout << u << " ";
}

int main() {
	freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);

	solve();
	
	//cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
	return 0;
}