#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;

	int X = m, time = 0;
	while (N > 0) {
		if (X + T <= M) {
			X += T;
			N--;
		}
		else {
			if (X - R >= m) X -= R;
			else X = m;

			if (m + T > M) {
				time = -1;
				break;
			}
		}
		time++;
	}

	cout << time;
}