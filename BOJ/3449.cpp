#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;

		int cnt = 0;
		for (int i = 0; s1[i]; i++) {
			if (s1[i] != s2[i]) cnt++;
		}
		cout << "Hamming distance is " << cnt << ".\n";
	}

	return 0;
}