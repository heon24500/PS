#include <iostream>
using namespace std;

int main() {
	int cnt1 = 0, cnt2 = 0, N;
	scanf("%d", &N);

	while (N--) {
		int num;
		scanf("%d", &num);

		if (num == 0) cnt1++;
		else cnt2++;
	}

	if (cnt1 > cnt2) printf("Junhee is not cute!");
	else printf("Junhee is cute!");
}