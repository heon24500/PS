#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int n, first_circle;
	cin >> n;
	cin >> first_circle;
	for (int i = 1; i < n; i++) {
		int now_circle;
		cin >> now_circle;
		if (first_circle % now_circle == 0) cout << first_circle / now_circle << "/" << "1\n";
		else if (now_circle % first_circle == 0) cout << "1/" << now_circle / first_circle << "\n";
		else {
			int g = gcd(first_circle, now_circle);
			cout << first_circle / g << "/" << now_circle / g << "\n";
		}
	}

	return 0;
}