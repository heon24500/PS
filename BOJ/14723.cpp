#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, a = 1, b = 1, sum = 2;
	cin >> N;

	while (N--) {
		if (a == 1) {
			a = sum - 1;
			b = 1;
			sum++;
		}
		else {
			a--;
			b++;
		}
	}

	cout << a << " " << b;
}