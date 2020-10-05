#include <iostream>
using namespace std;

const int N = 11, K = 11;
int c[N][K];

int main() {
	int n, k;
	cin >> n >> k;
	c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	cout << c[n][k];

	return 0;
}