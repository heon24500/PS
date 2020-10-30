#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int j, n;
		cin >> j >> n;

		vector<int> box;
		for (int i = 0; i < n; i++) {
			int r, c;
			cin >> r >> c;
			box.push_back(r * c);
		}

		int ans = 0;
		sort(box.begin(), box.end(), greater<int>());
		for (int i = 0; ; i++) {
			if (j <= 0) break;
			j -= box[i];
			ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}