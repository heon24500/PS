#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int I, sum = 0;
	cin >> I;

	for (int i = 1; i <= I; i++) {
		if (I % i == 0) sum += i;
	}

	cout << sum;
}