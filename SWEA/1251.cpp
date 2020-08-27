/* 1251. [S/W 문제해결 응용] 4일차 - 하나로 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

double e;
ll parent[1000];
ll n;
ll ret;
pll islands[1000];
vector<pair<pll, ll> > vw;

bool comp(pair<pll, ll> a, pair<pll, ll> b) {
	return a.second < b.second;
}

void Make_Set(int v) {
	parent[v] = v;
}

int Find_Set(int v) {
	if (parent[v] == v) return v;
	else return parent[v] = Find_Set(parent[v]);
}

void Union(int u, int v) {
	u = Find_Set(u);
	v = Find_Set(v);
	if (u != v) parent[v] = u;
}

ll calcWeight(pll a, pll b) {
	ll L1 = (a.first - b.first) * (a.first - b.first);
	ll L2 = (a.second - b.second)* (a.second - b.second);
	return L1 + L2;
}

void Kruskal() {
	for (int i = 0; i < n; i++) {
		Make_Set(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pll uv = make_pair(i, j);
			ll weight = calcWeight(islands[i], islands[j]);
			vw.push_back(make_pair(uv, weight));
		}
	}
	sort(vw.begin(), vw.end(), comp);

	int selected = 0;
	for (int i = 0; i < vw.size(); i++) {
		pll uv = vw[i].first;
		int u = uv.first;
		int v = uv.second;
		if (Find_Set(u) != Find_Set(v)) {
			selected++;
			ret += vw[i].second;
			Union(u, v);
		}
		if (selected == n) return;
	}
}

void init() {
	vw.clear();
	ret = 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> islands[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> islands[i].second;
		}
		cin >> e;

		Kruskal();

		cout << fixed;
		cout.precision(0);
		cout << "#" << tc << " " << (double)(e * ret) << '\n';
		init();
	}

	return 0;
}