#include <iostream>
using namespace std;

int mod(string str, int n) {
	int ret = 0;
	for (int i = 0; str[i]; i++) {
		ret = (ret * 10 + str[i] - '0') % n;
	}
	return ret;
}

void solve(string str, int k) {
	for (int i = 2; i < k; i++) {
		if (mod(str, i) != 0) continue;
		cout << "BAD " << i;
		return;
	}
	cout << "GOOD";
}

int main() {
	string p;
	int k;
	cin >> p >> k;
	solve(p, k);

	return 0;
}