#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string str;
		cin >> str;
		if (str == "end") break;
		bool flag = false;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; str[i]; i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				flag = true;
				cnt2 = 0;
				cnt1++;
				if (cnt1 == 3) break;
			}
			else {
				cnt1 = 0;
				cnt2++;
				if (cnt2 == 3) break;
			}

			if (i != 0 && str[i] == str[i - 1] && str[i] != 'e' && str[i] != 'o') {
				flag = false;
				break;
			}
		}

		cout << "<" << str << "> is ";
		if (!flag || cnt1 == 3 || cnt2 == 3) cout << "not ";
		cout << "acceptable.\n";
	}

	return 0;
}