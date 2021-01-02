#include <iostream>
using namespace std;

int main() {
	for (int tc = 1; ; tc++) {
		string str1, str2;
		cin >> str1 >> str2;
		if (str1 == "END") break;

		bool isSame = true;
		int cnt[150] = { 0 };
		for (int i = 0; str1[i]; i++) cnt[str1[i]]++;
		for (int i = 0; str2[i]; i++) cnt[str2[i]]--;
		for (int i = 'a'; i <= 'z'; i++) {
			if (cnt[i] != 0) {
				isSame = false;
				break;
			}
		}

		cout << "Case " << tc << ": ";
		if (isSame) cout << "same\n";
		else cout << "different\n";
	}

	return 0;
}
