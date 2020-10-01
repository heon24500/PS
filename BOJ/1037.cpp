#include <iostream>
using namespace std;

int main() {
	int n, min_num = 1e9, max_num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		min_num = min(min_num, num);
		max_num = max(max_num, num);
	}
	cout << min_num * max_num;
}