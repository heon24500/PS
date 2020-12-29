#include <iostream>
#include <queue>
using namespace std;

bool command(string str) {
	if (str.length() != 7) return false;
	char a = str[0];
	char b = str[2];
	if (a == b) return false;
	if (str[1] == a && str[3] == b && str[4] == a && str[5] == b && str[6] == b) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		cout << command(str) << '\n';
	}

	return 0;
}