#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int ret = 0, min = 50;
	if (a.length() != b.length()) {
		for (int i = 0; i <= b.length() - a.length(); i++) {
			int ret = 0;
			for (int j = 0; j < a.length(); j++) {
				if (a[j] != b[j + i]) ret++;
			}
			if (min > ret) min = ret;
		}
		cout << min;
	}
	else {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) ret++;
		}
		cout << ret;
	}

	return 0;
}