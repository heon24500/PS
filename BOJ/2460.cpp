#include <iostream>
using namespace std;

int main() {
	int num = 0, ans = 0;
	for (int i = 0; i < 10; i++) {
		int in_num, out_num;
		cin >> out_num >> in_num;
		num += in_num - out_num;
		ans = max(ans, num);
	}
	cout << ans;

	return 0;
}