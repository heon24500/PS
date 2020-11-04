#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		string str;
		getline(cin, str);
		if (str == "END") break;

		for (int i = str.length() - 1; i >= 0; i--) cout << str[i];
		cout << "\n";
	}

	return 0;
}