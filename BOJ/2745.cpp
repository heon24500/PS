#include <iostream>
using namespace std;

int main() {
	string n;
	int b;
	cin >> n >> b;

	int ret = 1, result = 0, num;
	for (int i = n.length() - 1; i >= 0; i--) {
		if (n[i] >= 'A') num = n[i] - 'A' + 10;
		else num = n[i] - '0';
		result += num * ret;
		ret *= b;
	}
	cout << result;

	return 0;
}