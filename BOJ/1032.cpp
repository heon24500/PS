#include <iostream>
using namespace std;

const int N = 51;
int n;
string str[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	int len = str[0].length();
	for (int i = 0; i < len; i++) {
		char ch = str[0][i];
		bool flag = true;
		for (int j = 1; j < n; j++) {
			if (ch != str[j][i]) flag = false;
			if (!flag) break;
		}
		if (flag) cout << ch;
		else cout << '?';
	}
	cout << '\n';

	return 0;
}