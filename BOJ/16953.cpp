#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

int solve(int src, int dest) {
	queue<pii> q;
	q.push({ src, 0 });

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		ll num = now.first;
		int dist = now.second;
		if (num == dest) return dist + 1;

		if (num * 2 <= dest) q.push({ num * 2, dist + 1 });
		if (num * 10 + 1 <= dest) q.push({ num * 10 + 1, dist + 1 });
	}

	return -1;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << solve(a, b);

	return 0;
}