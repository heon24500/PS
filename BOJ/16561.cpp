#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, cnt = 0;
	cin >> n;

	n /= 3;

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= n - 1 - i; j++) {
			cnt++;
		}
	}

	cout << cnt;
}