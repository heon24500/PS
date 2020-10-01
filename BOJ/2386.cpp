#include <iostream>
using namespace std;

int main() {
	while (true) {
		char ch;
		cin >> ch;
		if (ch == '#') break;

		char buf[255];
		fgets(buf, 255, stdin);
		int cnt = 0;
		for (int i = 0; buf[i]; i++) {
			int dif = abs(ch - buf[i]);
			if (dif == 0 || dif == 32) cnt++;
		}
		cout << ch << ' ' << cnt << '\n';
	}


	return 0;
}