#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		sum += ch - 'A' + 1;
	}
	cout << sum;

	return 0;
}
