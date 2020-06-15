#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1001;
int p[N], d[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], p[j] + d[i - j]);
		}
	}
	cout << d[n];

	return 0;
}