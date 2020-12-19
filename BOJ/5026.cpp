#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "P=NP") {
			cout << "skipped\n";
			continue;
		}

		int num1 = 0, num2 = 0;
		bool flag = false;
		for (int i = 0; str[i]; i++) {
			if (str[i] == '+') flag = true;
			else {
				if (flag) {
					num2 *= 10;
					num2 += str[i] - '0';
				}
				else {
					num1 *= 10;
					num1 += str[i] - '0';
				}
			}
		}
		cout << num1 + num2 << '\n';
	}

	return 0;
}