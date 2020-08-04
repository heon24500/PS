/* 1259. ÆÓ¸°µå·Ò¼ö */
#include <iostream>
using namespace std;

int main()
{
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		int num[10], len = 0;
		while (n > 0) {
			num[len++] = n % 10;
			n /= 10;
		}

		bool flag = true;
		for (int i = 0; i < len / 2; i++) {
			if (num[i] != num[len - i - 1]) {
				flag = false;
				break;
			}
		}
		if (flag) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}