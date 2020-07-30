/* 1436. ¿µÈ­°¨µ¶ ¼ò */
#include <iostream>
using namespace std;

bool isContain(int n) {
	int cnt = 0;
	while (n > 0) {
		if (n % 10 == 6) cnt++;
		else cnt = 0;

		if (cnt == 3) return true;
		n /= 10;
	}
	return false;
}

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 666; ; i++) {
		if (isContain(i)) cnt++;
		if (cnt == n) {
			cout << i;
			break;
		}
	}

	return 0;
}