#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, cnt = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		if (num != i) cnt++;
	}

	cout << cnt;
}