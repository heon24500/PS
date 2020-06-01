#include <iostream>
using namespace std;

const int N = 1000002;
bool check[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i <= N; i++) {
		if (!check[i]) {
			for (int j = i + i; j <= N; j += i) {
				check[j] = true;
			}
		}
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		bool flag = false;
		for (int a = 2; a <= n / 2; a++) {
			int b = n - a;
			if (!check[a] && !check[b]) {
				cout << n << " = " << a << " + " << b << "\n";
				flag = true;
				break;
			}
		}
		if (!flag) cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}