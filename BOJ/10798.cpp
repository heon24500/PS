#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str[5];

	int max = 0;
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		if (max < str[i].length()) max = str[i].length();
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j].length() <= i) continue;
			cout << str[j][i];
		}
	}

	return 0;
}