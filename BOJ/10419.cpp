#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	while (T--) {
		int d, delay = 0;
		scanf("%d", &d);

		while (true) {
			if (delay + delay * delay > d) {
				delay--;
				break;
			}
			else delay++;
		}

		printf("%d\n", delay);
	}
}