#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int ret = 0, idx = 1;
	while (b > 0) {
		int num = a * (b % 10);
		cout << num << '\n';
		ret += num * idx;
		idx *= 10;
		b /= 10;
	}
	cout << ret << '\n';

	return 0;
}