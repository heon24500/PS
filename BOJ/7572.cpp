#include <iostream>
using namespace std;

char gan[11] = "0123456789";
char ji[13] = "ABCDEFGHIJKL";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int diff = n - 2013;
	int g_idx = 9, j_idx = 5;
	g_idx = (g_idx + diff) % 10;
	j_idx = (j_idx + diff) % 12;
	if (g_idx < 0) g_idx += 10;
	if (j_idx < 0) j_idx += 12;
	cout << ji[j_idx] << gan[g_idx] << '\n';

	return 0;
}