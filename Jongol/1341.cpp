#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s, e;
	cin >> s >> e;

	if (s <= e) {
		for (int i = s; i <= e; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << i << " * " << j << " = ";
				if (i * j < 10) cout << " " << i * j;
				else cout << i * j;
				cout << "   ";
				if (j % 3 == 0) cout << '\n';
			}
			cout << '\n';
		}
	}
	else {
		for (int i = s; i >= e; i--) {
			for (int j = 1; j <= 9; j++) {
				cout << i << " * " << j << " = ";
				if (i * j < 10) cout << " " << i * j;
				else cout << i * j;
				cout << "   ";
				if (j % 3 == 0) cout << '\n';
			}
			cout << '\n';
		}
	}

	return 0;
}