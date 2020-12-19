#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	getline(cin, str);
	while (n--) {
		getline(cin, str);
		int g = 0, b = 0;
		for (int i = 0; str[i]; i++) {
			if (str[i] == 'g' || str[i] == 'G') g++;
			if (str[i] == 'b' || str[i] == 'B') b++;
		}
		if (g > b) cout << str << " is GOOD\n";
		else if (g < b) cout << str << " is A BADDY\n";
		else cout << str << " is NEUTRAL\n";
	}

	return 0;
}