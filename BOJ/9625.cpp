#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	string str = "A";
	pair<int, int> cnt = { 1, 0 };
	for (int i = 0; i < k; i++) {
		int nums_a = cnt.first;
		int nums_b = cnt.second;

		cnt.first = nums_b;
		cnt.second = nums_a + nums_b;
	}
	cout << cnt.first << " " << cnt.second;

	return 0;
}