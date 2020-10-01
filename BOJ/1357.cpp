#include <iostream>
#include <string>
using namespace std;

int rev(string str) {
	string ret;
	int len = str.length();
	for (int i = len - 1; i >= 0; i--) {
		ret += str[i];
	}

	return stoi(ret);
}

int main() {
	string x, y;
	cin >> x >> y;
	int ret = rev(x) + rev(y);
	string str = to_string(ret);
	cout << rev(str);

	return 0;
}