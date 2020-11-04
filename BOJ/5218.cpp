#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;

		cout << "Distances: ";
		for (int i = 0; s1[i]; i++) {
			int num = s2[i] - s1[i];
			if (num < 0) num += 26;
			cout << num << " ";
		}
		cout << '\n';
	}

	return 0;
}
