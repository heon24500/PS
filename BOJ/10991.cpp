#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) printf(" ");
		for (int j = 1; j <= i; j++) printf("* ");
		printf("\n");
	}
}