#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	string bn;
	while (x > 0) {
		bn += (x % 2) + '0';
		x /= 2;
	}
	int cnt = 0;
	for (int i = 0; bn[i]; i++) {
		if (bn[i] == '1') cnt++;
	}
	cout << cnt;

	return 0;
}