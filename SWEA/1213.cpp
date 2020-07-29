/* 1213. [S/W 문제해결 기본] 3일차 - String */
#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int t_num;
		cin >> t_num;

		string find, str;
		cin >> find;
		cin >> str;

		int cnt = 0;
		for (int i = 0; i < str.length() - find.length() + 1; i++) {
			bool flag = true;
			for (int j = 0; j < find.length(); j++) {
				if (str[i + j] != find[j]) flag = false;
			}
			if (flag) cnt++;
		}

		cout << "#" << t_num << " " << cnt << '\n';
	}

	return 0;
}