#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long N, F;
	cin >> N >> F;

	if (N < 10) N *= 10;
	long rhs = N % 100;
	long lhs = N - rhs;

	long i;
	for (i = 0; i < 100; i++) {
		long ret = lhs + i;
		if (ret % F == 0) break;
	}

	if (i < 10) cout << "0";
	cout << i;
}