#include <iostream>
using namespace std;

const int N = 101;
int n;
char mat[N][N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mat[i][j] != mat[j][i]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}