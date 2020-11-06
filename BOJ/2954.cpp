#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	getline(cin, s);

	bool flag = false;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			if (flag) {
				flag = false;
				continue;
			}
			else {
				cout << s[i];
				flag = true;
			}
		}
		else if (flag) continue;
		else cout << s[i];
	}

	return 0;
}