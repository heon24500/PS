#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		int g = gcd(a, b);
		int lcm = g * (a / g) * (b / g);

		cout << lcm << "\n";
	}

	return 0;
}