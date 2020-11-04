#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		char a, b, temp;
		cin >> a >> temp >> b;
		cout << a - '0' + b - '0' << '\n';
	}

	return 0;
}