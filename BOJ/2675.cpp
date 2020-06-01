#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int r = 0;
		string s;

		cin >> r;
		cin >> s;

		int s_len = s.size();
		for (int j = 0; j < s_len; j++) {
			for (int k = 0; k < r; k++) {
				cout << s[j];
			}
		}

		cout << endl;
	}

	return 0;
}