#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int X, Y, N;
	cin >> X >> Y >> N;

	for (int i = 1; i <= N; i++) {
		if (i % X == 0) cout << "Fizz";
		if (i % Y == 0) cout << "Buzz";
		if (i % X != 0 && i % Y != 0) cout << i;
		cout << "\n";
	}
}