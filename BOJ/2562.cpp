#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num[10], max = 0, max_idx = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> num[i];
		if (max < num[i]) {
			max = num[i];
			max_idx = i;
		}
	}

	cout << max << "\n" << max_idx;

	return 0;
}