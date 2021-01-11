#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	int num = 0, cnt = 0;
	if (str.length() == 1) num = str[0] - '0';
	else {
		for (int i = 0; str[i]; i++) num += str[i] - '0';
		cnt = 1;

		while (num >= 10) {
			cnt++;

			int next = 0;
			while (num > 0) {
				next += num % 10;
				num /= 10;
			}
			num = next;
		}
	}

	cout << cnt << '\n';
	if (num % 3 == 0) cout << "YES";
	else cout << "NO";

	return 0;
}