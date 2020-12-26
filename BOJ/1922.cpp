#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int src;
	int dest;
	int weight;
};

bool compare(const Edge& e1, const Edge& e2) {
	return e1.weight < e2.weight;
}

const int N = 1001, M = 100001;
int n, m;
int parent[N];
vector<Edge> edges;

int getParent(int idx) {
	if (parent[idx] == idx) return idx;
	return parent[idx] = getParent(parent[idx]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}
	sort(edges.begin(), edges.end(), compare);

	int ans = 0;
	for (auto& edge : edges) {
		int a = edge.src;
		int b = edge.dest;
		int w = edge.weight;
		if (findParent(a, b)) continue;
		unionParent(a, b);
		ans += w;
	}
	cout << ans;

	return 0;
}