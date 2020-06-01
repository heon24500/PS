#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (prev_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	else cout << "-1";

	return 0;
}