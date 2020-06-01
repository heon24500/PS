#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005
int weight[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	sort(weight, weight + n);

	int now_weight = 0, max = 0;
	for (int i = n - 1; i >= 0; i--) {
		now_weight = weight[i] * (n - i);
		if (max < now_weight) max = now_weight;
	}
	cout << max;

	return 0;
}