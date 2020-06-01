#include <iostream>
using namespace std;

int nums[9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> nums[i];
		sum += nums[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			int this_sum = sum - nums[i] - nums[j];
			if (this_sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << nums[k] << "\n";
				}

				return 0;
			}
		}
	}

	return 0;
}