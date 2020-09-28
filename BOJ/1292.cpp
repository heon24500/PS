#include <iostream>
using namespace std;

const int N = 1005;
int arr[N];

void init() {
	int idx = 0, num = 1;
	while (true) {
		for (int i = 1; i <= num; i++) {
			arr[idx++] = num;
			if (idx >= N) return;
		}
		num++;
	}
}

int main() {
	int a, b, sum = 0;
	init();
	cin >> a >> b;
	for (int i = a - 1; i < b; i++) {
		sum += arr[i];
	}
	cout << sum;

	return 0;
}