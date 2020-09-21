#include <iostream>
using namespace std;

const int N = 100;
int n, order[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		order[i] = i + 1;
		int num;
		cin >> num;
		if (num == 0) continue;

		int idx = i - num;
		int temp = order[i];
		for (int j = i; j > idx; j--) {
			order[j] = order[j - 1];
		}
		order[idx] = temp;
	}

	for (int i = 0; i < n; i++) {
		cout << order[i] << ' ';
	}

	return 0;
}