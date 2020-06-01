#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nums[3];
	for (int i = 0; i < 3; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + 3);
	int diff1 = nums[1] - nums[0];
	int diff2 = nums[2] - nums[1];
	int diff3 = nums[2] - nums[0];

	if (diff1 == diff2) {
		// 4 6 8
		cout << nums[2] + diff1;
	}
	else if (diff1 == diff2 * 2) {
		// 4 8 10
		cout << nums[0] + diff2;
	}
	else if (diff2 == diff1 * 2) {
		// 4 6 10
		cout << nums[1] + diff1;
	}

	return 0;
}