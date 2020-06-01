#include <iostream>
using namespace std;

int main() {
	int N, ret = 1;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		ret *= i;
	}

	printf("%d", ret);
}