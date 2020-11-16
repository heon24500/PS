#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s[s.length() - 1] % 2 == 0) cout << "even\n";
		else cout << "odd\n";
	}

	return 0;
}