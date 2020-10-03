#include <iostream>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b >> n;

	int ret = 0;
	for (int i = 0; i <= n; i++) {
		ret = a / b;
		a = (a % b) * 10;
	}
	cout << ret;

	return 0;
}