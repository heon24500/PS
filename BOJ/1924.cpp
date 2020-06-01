#include <iostream>
#include <string>
using namespace std;

int main() {
	int x, y, cnt = 0;
	string str[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	cin >> x >> y;

	for (int i = 1; i <= 12; i++) {
		if (i == x) {
			for (int j = 1; j <= y; j++) {
				cnt++;
			}
			break;
		}
		else {
			if ((i == 4) || (i == 6) || (i == 9) || (i == 11)) {
				for (int j = 1; j <= 30; j++) {
					cnt++;
				}
			}
			else if (i == 2) {
				for (int j = 1; j <= 28; j++) {
					cnt++;
				}
			}
			else {
				for (int j = 1; j <= 31; j++) {
					cnt++;
				}
			}
		}
	}

	cnt %= 7;
	cout << str[cnt] << endl;

	return 0;
}