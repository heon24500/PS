#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int maxi = -1e9, mini = 1e9;

		int num;
		while (n--) {
			cin >> num;
			maxi = max(maxi, num);
			mini = min(mini, num);
		}

		cout << mini << " " << maxi << '\n';
	}

	return 0;
}