#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int num, cnt = 0;
	while (cin >> num) {
		if (num > 0) cnt++;
	}

	cout << cnt;
}