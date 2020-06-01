#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int k;
		cin >> k;
		if (k == 0) break;

		vector<int> a(k), select(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
			if (i < k - 6) select[i] = 0;
			else select[i] = 1;
		}

		vector<vector<int> > ret;
		while (true) {
			vector<int> current;
			for (int i = 0; i < k; i++) {
				if (select[i]) current.push_back(a[i]);
			}
			ret.push_back(current);
			if (!next_permutation(select.begin(), select.end())) break;
		}

		sort(ret.begin(), ret.end());
		for (auto& v : ret) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}