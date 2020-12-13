#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	long long num = 0, sum = 0;
	bool flag = false;
	for (int i = 0; str[i]; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num *= 10;
			num += str[i] - '0';
			flag = true;
		}
		else {
			if (flag) {
				sum += num;
				num = 0;
				flag = false;
			}
		}
	}
	if (flag) sum += num;
	cout << sum;

	return 0;
}