#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string str1, str2, str;
		cin >> str1 >> str2;
		getline(cin, str);
		for (int i = 1; str[i]; i++) cout << str[i];
		cout << " " << str1 << " " << str2 << '\n';
	}

	return 0;
}