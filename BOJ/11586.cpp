#include <iostream>
#include <string>
using namespace std;

const int N = 100;
int n, k;
string s[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	cin >> k;

	if (k == 1) {
		for (int i = 0; i < n; i++) cout << s[i] << '\n';
	}
	else if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = s[i].length() - 1; j >= 0; j--) cout << s[i][j];
			cout << '\n';
		}
	}
	else {
		for (int i = n - 1; i >= 0; i--) cout << s[i] << '\n';
	}

	return 0;
}
