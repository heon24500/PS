#include <iostream>
using namespace std;

int main() {
	int diff = 'a' - 'A';
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= diff;
		else str[i] += diff;
	}
	cout << str;

	return 0;
}