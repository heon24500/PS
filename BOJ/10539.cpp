#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, sum = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int b;
		scanf("%d", &b);

		b = (b * i) - sum;
		sum += b;
		printf("%d ", b);
	}
}