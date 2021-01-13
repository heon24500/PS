#include <iostream>
using namespace std;

int main() {
	string str, ans = "";
	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'E') ans += 'I';
		else if (str[i] == 'I') ans += 'E';
		else if (str[i] == 'S') ans += 'N';
		else if (str[i] == 'N') ans += 'S';
		else if (str[i] == 'T') ans += 'F';
		else if (str[i] == 'F') ans += 'T';
		else if (str[i] == 'J') ans += 'P';
		else if (str[i] == 'P') ans += 'J';
	}
	cout << ans;

	return 0;
}