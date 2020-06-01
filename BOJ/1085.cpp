#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int dist[4] = { x, y, w - x, h - y };
	sort(dist, dist + 4);
	cout << dist[0];
}