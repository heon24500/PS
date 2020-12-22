#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 51;
int n, m, k, ans;
int know[N];
bool check[N];
vector<int> party[N];
vector<int> adj[N];

void solve() {
	for (int i = 0; i < k; i++) {
		if (check[know[i]]) continue;

		queue<int> q;
		q.push(know[i]);
		check[know[i]] = true;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int u : adj[now]) {
				if (check[u]) continue;
				q.push(u);
				check[u] = true;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		bool flag = true;
		for (int j = 0; j < party[i].size(); j++) {
			if (check[party[i][j]]) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}
}

int main() {
	cin >> n >> m;
	cin >> k;
	for (int i = 0; i < k; i++) cin >> know[i];
	for (int i = 0; i < m; i++) {
		int nums;
		cin >> nums;
		int first_node = 0;
		for (int j = 0; j < nums; j++) {
			int num;
			cin >> num;
			party[i].push_back(num);
			if (j == 0) first_node = num;
			else {
				adj[first_node].push_back(num);
				adj[num].push_back(first_node);
			}
		}
	}

	solve();
	cout << ans;

	return 0;
}