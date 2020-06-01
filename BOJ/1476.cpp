#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int e, s, m;
	cin >> e >> s >> m;

	e--;
	s--;
	m--;

	int year = 0;
	while (true) {
		if (year % 15 == e && year % 28 == s && year % 19 == m) break;
		year++;
	}
	cout << year + 1;

	return 0;
}