#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	while (true) {
		cnt++;
		int a, b;
		string op;
		cin >> a >> op >> b;
		if (op == "E") break;

		bool result = false;
		if (op == ">") result = a > b;
		if (op == ">=") result = a >= b;
		if (op == "<") result = a < b;
		if (op == "<=") result = a <= b;
		if (op == "==") result = a == b;
		if (op == "!=") result = a != b;

		cout << "Case " << cnt << ": ";
		if (result) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}