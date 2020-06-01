#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	while (T--) {
		int V, E, P;
		scanf("%d %d", &V, &E);

		P = 2 - V + E;
		printf("%d\n", P);
	}
}