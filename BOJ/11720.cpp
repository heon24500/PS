#include <iostream>
using namespace std;

int main() {
	int n, in_num, sum = 0;
	char in;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		in_num = in - 48;

		sum += in_num;
	}

	cout << sum << endl;

	return 0;
}