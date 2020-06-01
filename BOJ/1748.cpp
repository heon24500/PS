#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num = 10, sum = 0, ret = 9, cnt = 1;
	cin >> n;

	while (true) {
		if (n >= num) {
			sum += ret * cnt;
			ret *= 10;
			num *= 10;
			cnt++;
		}
		else {
			sum += (n - num / 10 + 1) * cnt;
			break;
		}
	}

	cout << sum;

	return 0;
}