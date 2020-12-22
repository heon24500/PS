#include <iostream>
#include <vector>
using namespace std;

const int N = 50;
int n, root, target, ans;
bool visited[N];
vector<int> adj[N];

void dfs(int node) {
	if (visited[node]) return;
	visited[node] = true;

	bool flag = true;
	for (int u : adj[node]) {
		if (visited[u]) continue;
		flag = false;
		dfs(u);
	}
	if (flag) ans++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) root = i;
		else adj[parent].push_back(i);
	}
	cin >> target;
	visited[target] = true;

	dfs(root);
	cout << ans;

	return 0;
}