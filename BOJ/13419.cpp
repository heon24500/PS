#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		string a, b;
		if (s.length() % 2 == 0) {
			for (int i = 0; s[i]; i++) {
				if (i % 2 == 0) a += s[i];
				else b += s[i];
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; s[j]; j++) {
					if (i % 2 == 0) {
						if (j % 2 == 0) a += s[j];
						else b += s[j];
					}
					else {
						if (j % 2 == 0) b += s[j];
						else a += s[j];
					}
				}
			}
		}

		cout << a << '\n' << b << '\n';
	}

	return 0;
}