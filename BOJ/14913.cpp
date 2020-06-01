#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a, d, k;
	cin >> a >> d >> k;

	int i = 0;
	bool isFound = false;

	if (d > 0) {
		while (a <= k) {
			i++;
			if (k == a) isFound = true;
			a += d;
		}
	}
	else {
		while (a >= k) {
			i++;
			if (k == a) isFound = true;
			a += d;
		}
	}

	if (isFound) cout << i;
	else cout << "X";
}