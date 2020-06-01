#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005

int num[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0, sum = 0;
	string str;
	cin >> str;

	bool flag = false;
	for (n = 0; n < str.length(); n++) {
		num[n] = str[n] - '0';
		sum += num[n];
		if (num[n] == 0) flag = true;
	}

	if (!flag || sum % 3 != 0) cout << "-1";
	else {
		sort(num, num + n);
		for (int i = n - 1; i >= 0; i--) {
			cout << num[i];
		}
	}

	return 0;
}