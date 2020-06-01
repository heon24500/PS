#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		cout << "String #" << i + 1 << "\n";
		for (int j = 0; j < str.length(); j++) {
			char ch = str[j] + 1;
			if (str[j] == 'Z') ch = 'A';
			cout << ch;
		}
		cout << "\n\n";
	}

	return 0;
}