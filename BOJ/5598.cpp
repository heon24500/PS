#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	for (int i = 0; str[i]; i++) {
		if (str[i] <= 'C') str[i] = str[i] - 'A' + 'Z' + 1;
		str[i] -= 3;
		cout << str[i];
	}

	return 0;
}