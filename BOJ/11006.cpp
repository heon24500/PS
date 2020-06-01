#include <iostream>
using namespace std;

int main() {
	int T, U = 0, V = 0;
	scanf("%d", &T);

	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);

		U = M;
		N -= M;

		U -= N;
		V = N;

		printf("%d %d\n", U, V);
	}
}