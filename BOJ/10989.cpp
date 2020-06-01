#include <iostream>
using namespace std;

#define N 10005

int num[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int here;
		cin >> here;
		num[here]++;
	}

	for (int i = 0; i <= 10000; i++) {
		for (int j = 0; j < num[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}