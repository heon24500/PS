#include <iostream>
using namespace std;

const int N = 100001;
int d[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (d[i] > d[i - j * j] + 1) d[i] = d[i - j * j] + 1;
		}
	}
	cout << d[n];

	return 0;
}