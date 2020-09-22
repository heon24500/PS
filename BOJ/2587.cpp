#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int avg = 0;
	int nums[5];
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		avg += num / 5;
		nums[i] = num;
	}
	sort(nums, nums + 5);
	cout << avg << '\n' << nums[2] << '\n';
	return 0;
}