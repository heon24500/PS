#include <iostream>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;

	int cnt[1001] = { 0 };
	cnt[n] = 1;
	int num = n;
	for (int i = 2; ; i++) {
		n = (n * num) % p;
		if (cnt[n]) {
			cout << i - cnt[n];
			break;
		}
		else cnt[n] = i;
	}

	return 0;
}