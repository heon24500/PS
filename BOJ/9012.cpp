#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		char ch[51];
		int idx = 0;
		string str;
		cin >> str;

		bool is_VPS = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') ch[++idx] = '(';
			else {
				// case : str[i] == ')'
				if (i == 0) {
					is_VPS = false;
					break;
				}

				if (ch[idx] == '(') ch[idx--] = '0';
				else {
					is_VPS = false;
					break;
				}
			}
		}
		if (is_VPS && ch[1] == '(') is_VPS = false;
		if (is_VPS) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}