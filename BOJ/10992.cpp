#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N;
	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) printf(" ");
		printf("*");
		for (int j = 1; j < 2 * i - 2; j++) printf(" ");
		if (i > 1) printf("*");
		printf("\n");
	}
	for (int i = 1; i <= 2 * N - 1; i++) printf("*");
}