#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long a, b, v;
	cin >> a >> b >> v;

	long ret = (v - b) / (a - b);
	if ((v - b) % (a - b) != 0) ret++;
	cout << ret;

	return 0;
}