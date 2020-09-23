#include <iostream>
using namespace std;

const int N = 100001;
int temp[N], sum[N];

int main() {
	int n, k, ret = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
		if (i == 0) sum[i] = temp[i];
		else sum[i] = sum[i - 1] + temp[i];

		if (i < k) ret += temp[i];
		if (i >= k) {
			int now = sum[i] - sum[i - k];
			if (ret < now) ret = now;
		}
	}

	cout << ret;

	return 0;
}