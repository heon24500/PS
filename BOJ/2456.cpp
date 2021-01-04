#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int point[4] = { 0 };
	int cnt[4][4] = { 0 };
	for (int i = 1; i <= n; i++) {
		int vote[4];
		for (int j = 1; j <= 3; j++) {
			cin >> vote[j];
			cnt[j][vote[j]]++;
			point[j] += vote[j];
		}
	}

	int max_candidate = 1;
	bool flag = true;
	for (int i = 2; i <= 3; i++) {
		if (point[max_candidate] < point[i]) {
			max_candidate = i;
			flag = true;
		}
		else if (point[max_candidate] == point[i]) {
			flag = false;
			for (int j = 3; j >= 2; j--) {
				if (cnt[max_candidate][j] > cnt[i][j]) {
					flag = true;
					break;
				}
				else if (cnt[max_candidate][j] < cnt[i][j]) {
					max_candidate = i;
					flag = true;
					break;
				}
			}

		}
	}
	if (flag) cout << max_candidate;
	else cout << 0;
	cout << " " << point[max_candidate];

	return 0;
}