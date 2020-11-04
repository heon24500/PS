#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		cout << str[0] << str[str.length() - 1] << '\n';
	}

	return 0;
}