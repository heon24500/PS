#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	while (n / 10 > 0) {
		int temp = 1;
		while (n > 0) {
			temp *= n % 10;
			n /= 10;
		}
		n = temp;
		ans++;
	}
	cout << ans;

	return 0;
}