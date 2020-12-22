#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	bool flag = false;
	int cnt_left = 0, cnt_right = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '0') flag = true;
		else if (str[i] == '@') {
			if (flag) cnt_right++;
			else cnt_left++;
		}
	}
	cout << cnt_left << " " << cnt_right;

	return 0;
}