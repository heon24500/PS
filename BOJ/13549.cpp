#include <iostream>
#include <deque>
using namespace std;

const int X = 100001;
bool visited[X];
int dist[X];
deque<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	q.push_back(n);
	visited[n] = true;
	dist[n] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop_front();

		if (now * 2 < X && !visited[now * 2]) {
			q.push_front(now * 2);
			visited[now * 2] = true;
			dist[now * 2] = dist[now];
		}
		if (now - 1 >= 0 && !visited[now - 1]) {
			q.push_back(now - 1);
			visited[now - 1] = true;
			dist[now - 1] = dist[now] + 1;
		}
		if (now + 1 < X && !visited[now + 1]) {
			q.push_back(now + 1);
			visited[now + 1] = true;
			dist[now + 1] = dist[now] + 1;
		}
	}

	cout << dist[k];

	return 0;
}