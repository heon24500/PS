#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int limit;
	if (n == 2) limit = gcd(v[0], v[1]);
	else limit = gcd(gcd(v[0], v[1]), v[2]);
	for (int i = 1; i <= limit; i++) {
		if (limit % i == 0) cout << i << '\n';
	}

	return 0;
}