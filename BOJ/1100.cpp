#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char chess[8][8];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> chess[i][j];
			if (i % 2 == 0 && j % 2 == 0 && chess[i][j] == 'F') cnt++;
			else if (i % 2 != 0 && j % 2 != 0 && chess[i][j] == 'F') cnt++;
		}
	}

	cout << cnt;
}