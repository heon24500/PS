#include <iostream>
using namespace std;

typedef long long ll;

const int N = 10000;
int x[N];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += abs(x[i] - x[j]);
		}
	}
	cout << sum;

	return 0;
}