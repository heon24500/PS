#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num[3];
	for (int i = 0; i < 3; i++) {
		cin >> num[i];
	}
	string str;
	cin >> str;

	sort(num, num + 3);
	for (int i = 0; i < 3; i++) {
		cout << num[str[i] - 'A'] << ' ';
	}

	return 0;
}