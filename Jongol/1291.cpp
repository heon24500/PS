#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s, e;
	while (true) {
		cin >> s >> e;
		if (s < 2 || s > 9 || e < 2 || e > 9) cout << "INPUT ERROR!\n";
		else break;
	}

	if (s <= e) {
		for (int i = 1; i <= 9; i++) {
			for (int j = s; j <= e; j++) {
				cout << j << " * " << i << " = ";
				if (j * i < 10) cout << " " << j * i;
				else cout << j * i;
				cout << "   ";
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 1; i <= 9; i++) {
			for (int j = s; j >= e; j--) {
				cout << j << " * " << i << " = ";
				if (j * i < 10) cout << " " << j * i;
				else cout << j * i;
				cout << "   ";
			}
			cout << '\n';
		}
	}

	return 0;
}