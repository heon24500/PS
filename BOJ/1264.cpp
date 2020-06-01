#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int cnt = 0;
	while (true) {
		string str;
		cin >> str;

		if (str == "#") break;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') cnt++;
			if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') cnt++;
			if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
				cout << cnt << "\n";
				cnt = 0;
			}
		}
	}
}