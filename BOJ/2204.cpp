#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		vector<pair<string, string> > v;
		while (n--) {
			string str, temp = "";
			cin >> str;
			for (int i = 0; str[i]; i++) {
				if (str[i] >= 'A' && str[i] <= 'Z') temp += str[i] + 32;
				else temp += str[i];
			}
			v.push_back({ temp, str });
		}

		sort(v.begin(), v.end());
		cout << v[0].second << '\n';
	}

	return 0;
}