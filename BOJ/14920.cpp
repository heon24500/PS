#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, i = 1;
	cin >> n;

	while (n != 1) {
		if (n % 2 == 0) n /= 2;
		else n = 3 * n + 1;
		i++;
	}

	cout << i;
}