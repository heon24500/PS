#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, k;
	cin >> N >> k;

	int sum = N;
	for (int i = 0; i < k; i++) {
		N *= 10;
		sum += N;
	}

	cout << sum;
}