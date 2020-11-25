#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	int height = 10;
	for (int i = 1; str[i]; i++) {
		if (str[i] != str[i - 1]) height += 10;
		else height += 5;
	}
	cout << height;

	return 0;
}