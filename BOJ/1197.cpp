#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int V = 10001;
int v, e, ans;
int parent[V];

class Edge {
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	cin >> v >> e;

	vector<Edge> vect;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vect.push_back(Edge(a, b, c));
	}

	sort(vect.begin(), vect.end());

	for (int i = 0; i < v; i++) parent[i] = i;
	for (int i = 0; i < vect.size(); i++) {
		if (findParent(parent, vect[i].node[0], vect[i].node[1])) continue;
		ans += vect[i].distance;
		unionParent(parent, vect[i].node[0], vect[i].node[1]);
	}

	cout << ans;

	return 0;
}