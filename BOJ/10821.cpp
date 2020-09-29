#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	int len = str.length();
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ',') cnt++;
	}
	cout << cnt + 1;

	return 0;
}