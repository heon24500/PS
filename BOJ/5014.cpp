#include <iostream>
#include <queue>
using namespace std;

#define F 1000005
#define S 1000005
#define G 1000005
#define U 1000005
#define D 1000005

queue<int> q;
int dist[F];
bool visited[F];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	q.push(s);
	visited[s] = true;
	dist[s] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int tu = now + u;
		int td = now - d;

		if (tu >= 1 && tu <= f && !visited[tu]) {
			visited[tu] = true;
			q.push(tu);
			dist[tu] = dist[now] + 1;
		}

		if (td <= f && td >= 1 && !visited[td]) {
			visited[td] = true;
			q.push(td);
			dist[td] = dist[now] + 1;
		}
	}

	if (visited[g]) cout << dist[g];
	else cout << "use the stairs";

	return 0;
}