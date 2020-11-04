#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int num = 0, sum = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == ',') {
			sum += num;
			num = 0;
		}
		else num = (num * 10) + s[i] - '0';
	}
	sum += num;
	cout << sum;

	return 0;
}
