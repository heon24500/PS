#include <iostream>
using namespace std;

int strToInt(string str) {
	int ret = 0, i = 0;
	for (i = 0; i < str.length() - 1; i++) {
		if (str[i] == 'I') {
			if (str[i + 1] == 'V') {
				ret += 4;
				i++;
			}
			else if (str[i + 1] == 'X') {
				ret += 9;
				i++;
			}
			else ret += 1;
		}
		else if (str[i] == 'V') {
			ret += 5;
		}
		else if (str[i] == 'X') {
			if (str[i + 1] == 'L') {
				ret += 40;
				i++;
			}
			else if (str[i + 1] == 'C') {
				ret += 90;
				i++;
			}
			else ret += 10;
		}
		else if (str[i] == 'L') {
			ret += 50;
		}
		else if (str[i] == 'C') {
			if (str[i + 1] == 'D') {
				ret += 400;
				i++;
			}
			else if (str[i + 1] == 'M') {
				ret += 900;
				i++;
			}
			else ret += 100;
		}
		else if (str[i] == 'D') {
			ret += 500;
		}
		else if (str[i] == 'M') {
			ret += 1000;
		}
	}

	if (i == str.length() - 1) {
		if (str[i] == 'I') ret += 1;
		else if (str[i] == 'V') ret += 5;
		else if (str[i] == 'X') ret += 10;
		else if (str[i] == 'L') ret += 50;
		else if (str[i] == 'C') ret += 100;
		else if (str[i] == 'D') ret += 500;
		else if (str[i] == 'M') ret += 1000;
	}

	return ret;
}

string intToStr(int num) {
	string ret = "";

	while (num > 0) {
		if (num >= 1000) {
			ret += "M";
			num -= 1000;
		}
		else if (num >= 900) {
			ret += "CM";
			num -= 900;
		}
		else if (num >= 500) {
			ret += "D";
			num -= 500;
		}
		else if (num >= 400) {
			ret += "CD";
			num -= 400;
		}
		else if (num >= 100) {
			ret += "C";
			num -= 100;
		}
		else if (num >= 90) {
			ret += "XC";
			num -= 90;
		}
		else if (num >= 50) {
			ret += "L";
			num -= 50;
		}
		else if (num >= 40) {
			ret += "XL";
			num -= 40;
		}
		else if (num >= 10) {
			ret += "X";
			num -= 10;
		}
		else if (num >= 9) {
			ret += "IX";
			num -= 9;
		}
		else if (num >= 5) {
			ret += "V";
			num -= 5;
		}
		else if (num >= 4) {
			ret += "IV";
			num -= 4;
		}
		else if (num >= 1) {
			ret += "I";
			num -= 1;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str_num1, str_num2;
	cin >> str_num1 >> str_num2;

	int int_num1 = strToInt(str_num1);
	int int_num2 = strToInt(str_num2);
	int sum = int_num1 + int_num2;
	cout << sum << '\n' << intToStr(sum);

	return 0;
}