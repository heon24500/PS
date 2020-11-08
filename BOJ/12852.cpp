#include <iostream>
#include <vector>
using namespace std;

int ans = -1;
vector<int> vect;

void solve(int n, vector<int> v) {
	if (n == 1) {
		int len = v.size() - 1;
		if (ans == -1 || (ans != -1 && ans > len)) {
			ans = len;
			vect = v;
		}
		return;
	}

	if (ans != -1 && ans <= v.size() - 1) return;

	if (n % 3 == 0) {
		v.push_back(n / 3);
		solve(n / 3, v);
		v.pop_back();
	}
	if (n % 2 == 0) {
		v.push_back(n / 2);
		solve(n / 2, v);
		v.pop_back();
	}
	v.push_back(n - 1);
	solve(n - 1, v);
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(n);
	solve(n, v);
	cout << ans << '\n';
	for (int i = 0; i < vect.size(); i++) cout << vect[i] << ' ';

	return 0;
}