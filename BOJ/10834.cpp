#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int M, rot = 0, times = 1;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b, s;
		scanf("%d %d %d", &a, &b, &s);

		if (s == 1) {
			if (rot == 0) rot = 1;
			else rot = 0;
		}

		times = times / a * b;
	}

	printf("%d %d", rot, times);
}