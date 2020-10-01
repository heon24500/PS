#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	string max_a, max_b, min_a, min_b;
	for (int i = 0; a[i]; i++) {
		if (a[i] == '5') max_a += '6';
		else max_a += a[i];

		if (a[i] == '6') min_a += '5';
		else min_a += a[i];
	}
	for (int i = 0; b[i]; i++) {
		if (b[i] == '5') max_b += '6';
		else max_b += b[i];

		if (b[i] == '6') min_b += '5';
		else min_b += b[i];
	}

	int max_num = stoi(max_a) + stoi(max_b);
	int min_num = stoi(min_a) + stoi(min_b);
	cout << min_num << " " << max_num;

	return 0;
}