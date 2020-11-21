#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (true) {
		string s;
		getline(cin, s);
		if (s == "") break;
		str += s;
	}

	int sum = 0, num = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == ',') {
			sum += num;
			num = 0;
		}
		else num = num * 10 + str[i] - '0';
	}
	sum += num;
	cout << sum;

	return 0;
}