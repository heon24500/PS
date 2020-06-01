#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int C, K, P;
	cin >> C >> K >> P;

	int sum = 0;
	for (int i = 1; i <= C; i++) {
		sum += K * i + P * i * i;
	}

	cout << sum;
}