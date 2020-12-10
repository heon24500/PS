#include <iostream>
using namespace std;

int n;

void print() {
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < cnt; j++) cout << " ";
		for (int j = 1; j <= 2 * cnt - 1; j++) cout << "*";
		cout << '\n';
		if (i > n / 2) cnt--;
		else cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if (n >= 1 && n <= 100 && n % 2 != 0) print();
	else cout << "INPUT ERROR!";

	return 0;
}