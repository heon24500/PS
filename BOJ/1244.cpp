#include <iostream>
using namespace std;

const int N = 101;
int vect[N];
int n, m;

void toggle(int num) {
	if (vect[num]) vect[num] = 0;
	else vect[num] = 1;
}

void goBoy(int num) {
	for (int i = 1; i <= n; i++) {
		if (i % num == 0) toggle(i);
	}
}

void goGirl(int num) {
	int cnt = 1;
	int left, right;
	while (true) {
		left = num - cnt;
		right = num + cnt;
		if (left < 1 || right > n) break;
		if (vect[left] != vect[right]) break;
		cnt++;
	}

	for (int i = left + 1; i < right; i++) {
		toggle(i);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> vect[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int gender, num;
		cin >> gender >> num;
		if (gender == 1) goBoy(num);
		if (gender == 2) goGirl(num);
	}

	for (int i = 1; i <= n; i++) {
		cout << vect[i] << " ";
		if (i % 20 == 0) cout << '\n';
	}

	return 0;
}