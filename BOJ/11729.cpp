/* 11729. 하노이의 탑 이동 순서 */
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

vector<pii> v;
int ret = 0;

void hanoi(int s, int m, int d, int n) {
	ret++;

	if (n == 1) {
		v.push_back(make_pair(s, d));
		return;
	}

	hanoi(s, d, m, n - 1);
	v.push_back(make_pair(s, d));
	hanoi(m, s, d, n - 1);
}

int main() {
	int n;
	cin >> n;

	hanoi(1, 2, 3, n);

	cout << ret << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}