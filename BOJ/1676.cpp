#include <iostream>
using namespace std;

int countNumber(int target, int num) {
	int ret = 0;
	while (num % target == 0) {
		ret++;
		num /= target;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt_two = 0, cnt_five = 0, ret = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cnt_two += countNumber(2, i);
		cnt_five += countNumber(5, i);
	}
	cout << min(cnt_two, cnt_five);

	return 0;
}