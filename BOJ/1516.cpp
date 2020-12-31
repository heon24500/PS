#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1001;
int n;
int t[N], income[N], finish_time[N];
vector<int> adj[N];

void solve() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		finish_time[i] = t[i];
		if (income[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			finish_time[next] = max(finish_time[next], finish_time[now] + t[next]);
			income[next]--;
			if (income[next] == 0) q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		int num;
		cin >> num;
		while (num != -1) {
			adj[num].push_back(i);
			income[i]++;
			cin >> num;
		}
	}

	solve();
	for (int i = 1; i <= n; i++) cout << finish_time[i] << '\n';

	return 0;
}