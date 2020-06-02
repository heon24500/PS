#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

pii solve(vector<int> a, int result, int idx, int pl, int mi, int mu, int di) {
	if (idx == a.size()) return make_pair(result, result);

	vector<pii> res;
	if (pl > 0) res.push_back(solve(a, result + a[idx], idx + 1, pl - 1, mi, mu, di));
	if (mi > 0) res.push_back(solve(a, result - a[idx], idx + 1, pl, mi - 1, mu, di));
	if (mu > 0) res.push_back(solve(a, result * a[idx], idx + 1, pl, mi, mu - 1, di));
	if (di > 0) res.push_back(solve(a, result / a[idx], idx + 1, pl, mi, mu, di - 1));

	pii ret = res[0];
	for (auto now : res) {
		if (ret.first < now.first) ret.first = now.first;
		if (ret.second > now.second) ret.second = now.second;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int plus, minus, mult, div;
	cin >> plus >> minus >> mult >> div;

	pii ret = solve(a, a[0], 1, plus, minus, mult, div);
	cout << ret.first << '\n' << ret.second;

	return 0;
}