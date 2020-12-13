#include <iostream>
using namespace std;

bool isCorrect(string str) {
	int flag1 = 0, flag2 = 0, flag3 = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'p') {
			if (flag1 == 0 && flag2 == 0 && flag3 == 0) flag1 = 1;
			else return false;
		}
		else if (str[i] == 'i') {
			if (flag1 == 1 && flag2 == 0 && flag3 == 0) flag1 = 0;
			else return false;
		}
		else if (str[i] == 'k') {
			if (flag1 == 0 && flag2 == 0 && flag3 == 0) flag2 = 1;
			else return false;
		}
		else if (str[i] == 'a') {
			if (flag1 == 0 && flag2 == 1 && flag3 == 0) flag2 = 0;
			else return false;
		}
		else if (str[i] == 'c') {
			if (flag1 == 0 && flag2 == 0 && flag3 == 0) flag3 = 1;
			else return false;
		}
		else if (str[i] == 'h') {
			if (flag1 == 0 && flag2 == 0 && flag3 == 1) flag3 = 2;
			else return false;
		}
		else if (str[i] == 'u') {
			if (flag1 == 0 && flag2 == 0 && flag3 == 2) flag3 = 0;
			else return false;
		}
		else return false;
	}
	if (flag1 || flag2 || flag3) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	if (isCorrect(str)) cout << "YES";
	else cout << "NO";

	return 0;
}