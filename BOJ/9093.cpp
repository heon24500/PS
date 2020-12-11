#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	string str;
	getline(cin, str);
	while (t--) {
		getline(cin, str);

		string temp;
		for (int i = 0; str[i]; i++) {
			if (str[i] != ' ') temp += str[i];
			else {
				for (int j = temp.length() - 1; j >= 0; j--) cout << temp[j];
				cout << " ";
				temp = "";
			}
		}
		for (int j = temp.length() - 1; j >= 0; j--) cout << temp[j];
		cout << '\n';
	}

	return 0;
}