#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> n;

	while (true) {
		int num;
		cin >> num;
		if (num == -1) break;
		if (num != 0) n.push_back(num);
		else {
			int ret = 0;
			for (int i = 0; i < n.size(); i++) {
				for (int j = 0; j < n.size(); j++) {
					if (n[i] == n[j] * 2) ret++;
				}
			}
			cout << ret << "\n";
			n.clear();
		}
	}

	return 0;
}