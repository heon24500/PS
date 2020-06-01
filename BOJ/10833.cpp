#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, sum = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int student, apple;
		scanf("%d %d", &student, &apple);

		sum += apple % student;
	}

	printf("%d", sum);
}