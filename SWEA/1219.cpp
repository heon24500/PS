/* 1219. [S/W 문제해결 기본] 4일차 - 길찾기 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100];
bool visited[100];

void dfs(int n) {
	visited[n] = true;

	for (auto u : v[n]) {
		if (visited[u]) continue;
		dfs(u);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int t_num, len;
		cin >> t_num >> len;

		for (int i = 0; i < 100; i++) {
			visited[i] = 0;
			v[i].clear();
		}

		for (int i = 0; i < len; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}

		dfs(0);

		cout << "#" << t_num << " ";
		if (visited[99]) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}