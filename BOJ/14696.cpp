#include <iostream>
using namespace std;

int whoIsWin(int cnt_a[5], int cnt_b[5]) {
	for (int i = 4; i >= 1; i--) {
		if (cnt_a[i] > cnt_b[i]) return 1;
		if (cnt_a[i] < cnt_b[i]) return 2;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cnt_a[5] = { 0 };
		int cnt_b[5] = { 0 };

		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int num;
			cin >> num;
			cnt_a[num]++;
		}

		int b;
		cin >> b;
		for (int j = 0; j < b; j++) {
			int num;
			cin >> num;
			cnt_b[num]++;
		}

		int winner = whoIsWin(cnt_a, cnt_b);
		if (winner == 0) cout << "D\n";
		if (winner == 1) cout << "A\n";
		if (winner == 2) cout << "B\n";
	}
}