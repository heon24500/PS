#include <iostream>
using namespace std;

int cnt[43];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num[10], ret = 0;
	for (int i = 0; i < 10; i++) {
		cin >> num[i];
		cnt[num[i] % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (cnt[i] != 0) ret++;
	}

	cout << ret;

	return 0;
}