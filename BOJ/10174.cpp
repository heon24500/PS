#include <iostream>
#include <string>
using namespace std;

bool check(string str) {
	int len = str.length();
	for (int i = 0; i < len / 2; i++) {
		int dif = abs(str[i] - str[len - 1 - i]);
		if (dif == 0 || dif == 'a' - 'A') continue;
		return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	string str;
	getline(cin, str);
	while (n--) {
		getline(cin, str);
		if (str == "\n") continue;
		if (check(str)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}