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
		a[i] = i + 1;
	}

	while (true) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		if (!next_permutation(a.begin(), a.end())) break;
	}

	return 0;
}