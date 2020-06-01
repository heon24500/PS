#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, idx = 0, num[100000];
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int n;
		cin >> n;
		if (n == 0) idx--;
		else num[++idx] = n;
	}

	int sum = 0;
	for (int i = 1; i <= idx; i++) {
		sum += num[i];
	}
	cout << sum;

	return 0;
}