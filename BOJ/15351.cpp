#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	getline(cin, str);
	while (n--) {
		getline(cin, str);

		int score = 0;
		for (int i = 0; str[i]; i++) {
			if (str[i] == ' ') continue;
			score += str[i] - 'A' + 1;
		}
		if (score == 100) cout << "PERFECT LIFE\n";
		else cout << score << '\n';
	}

	return 0;
}