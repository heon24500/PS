#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	bool flag = false;
	int i, j;
	for (i = 0; i < a.length(); i++) {
		for (j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) flag = true;
			if (flag) break;
		}
		if (flag) break;
	}

	for (int h = 0; h < b.length(); h++) {
		for (int w = 0; w < a.length(); w++) {
			if (h == j) cout << a[w];
			else {
				if (w == i) cout << b[h];
				else cout << ".";
			}
		}
		cout << "\n";
	}

	return 0;
}