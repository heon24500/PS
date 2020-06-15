#include <iostream>
using namespace std;

const int N = 1001;
int d[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == 1) d[i] = 1;
		else d[i] = d[i - 1] % 10007 + (d[i - 2] * 2) % 10007;
	}
	cout << d[n] % 10007;

	return 0;
}