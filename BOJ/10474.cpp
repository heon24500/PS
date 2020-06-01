#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (true) {
		long long a, b;
		scanf("%lld %lld", &a, &b);

		if (a == 0 && b == 0) break;

		printf("%lld %lld / %lld\n", a / b, a % b, b);
	}
}