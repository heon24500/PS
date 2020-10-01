#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		string str;
		cin >> str;
		int ans = 0, cnt = 0;
		for (int j = 0; str[j]; j++) {
			if (j == 0) cnt = 1;
			else {
				if (str[j] != str[j - 1]) {
					if (ans < cnt) ans = cnt;
					cnt = 1;
				}
				else cnt++;
			}
		}
		if (ans < cnt) ans = cnt;
		cout << ans << '\n';
	}

	return 0;
}