#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int flag = 1;
	int cnt = 0;

	getline(cin, str);
	int len_str = str.size();

	for (int i = 0; i < len_str; i++) {
		if (str[i] == 32) {
			flag = 1;
		}
		else {
			if (flag == 1) {
				cnt++;
			}

			flag = 0;
		}
	}

	cout << cnt << endl;

	return 0;
}