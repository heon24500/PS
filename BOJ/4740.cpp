#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string str;
		getline(cin, str);
		if (str == "***") break;

		for (int i = str.length() - 1; i >= 0; i--) cout << str[i];
		cout << '\n';
	}

	return 0;
}