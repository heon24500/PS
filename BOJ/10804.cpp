#include <iostream>
using namespace std;

int mat[21];

void reverse(int src, int dest) {
	int n = (dest - src + 1) / 2;
	for (int i = 0; i < n; i++) swap(mat[src + i], mat[dest - i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 20; i++) mat[i] = i;

	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		reverse(a, b);
	}

	for (int i = 1; i <= 20; i++) cout << mat[i] << " ";

	return 0;
}