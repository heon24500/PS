#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector<int> nums;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());
	printf("%d %d", nums[0], nums[N - 1]);
}