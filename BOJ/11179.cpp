#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	while (n > 1) {
		v.push_back(n % 2);
		n /= 2;
	}
	if (n == 1) v.push_back(1);

	int ret = 0, cnt = 1;
	for (int i = v.size() - 1; i >= 0; i--) {
		ret += v[i] * cnt;
		cnt *= 2;
	}
	cout << ret;

	return 0;
}