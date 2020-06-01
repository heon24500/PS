#include <iostream>
using namespace std;

#define N 105
#define M 300005

int cards[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = cards[i] + cards[j] + cards[k];
				if (sum > m) continue;
				if (ret < sum) ret = sum;
			}
		}
	}

	cout << ret;

	return 0;
}