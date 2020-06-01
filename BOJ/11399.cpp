#include <iostream>
#include <algorithm>
using namespace std;

#define N 1005

int p[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	int times = 0, ret = 0;
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		times += p[i];
		ret += times;
	}
	cout << ret;

	return 0;
}