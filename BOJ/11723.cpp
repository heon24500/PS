#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int m, x, s = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			x--;
			s = s | (1 << x);
		}
		else if (str == "remove") {
			cin >> x;
			x--;
			s = s & ~(1 << x);
		}
		else if (str == "check") {
			cin >> x;
			x--;
			if (s & (1 << x)) cout << "1\n";
			else cout << "0\n";

		}
		else if (str == "toggle") {
			cin >> x;
			x--;
			s = s ^ (1 << x);
		}
		else if (str == "all") s = (1 << 20) - 1;
		else if (str == "empty") s = 0;
	}

	return 0;
}