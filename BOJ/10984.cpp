#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	while (T--) {
		int N, total_c = 0;
		float total_g = 0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			int C;
			float G;
			scanf("%d %f", &C, &G);
			total_c += C;
			total_g += (C * G);
		}

		printf("%d %.1f\n", total_c, total_g / total_c);
	}
}