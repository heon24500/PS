#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string str;
		getline(cin, str);
		if (str == "#") break;

		int cnt[150] = { 0 };
		for (int i = 0; str[i]; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') cnt[str[i] + 32]++;
			if (str[i] >= 'a' && str[i] <= 'z') cnt[str[i]]++;
		}

		int ret = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			if (cnt[i] > 0) ret++;
		}
		cout << ret << '\n';
	}

	return 0;
}