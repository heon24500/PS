#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;

	stack<int> s;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') s.push(-2);
		if (str[i] == '[') s.push(-3);
		if (str[i] == ')') {
			int sum = 0;
			while (true) {
				if (s.empty()) {
					cout << "0";
					return 0;
				}

				int num = s.top();
				s.pop();
				if (num == -2) {
					if (sum == 0) s.push(2);
					else s.push(sum * 2);
					break;
				}
				else sum += num;
			}
		}
		if (str[i] == ']') {
			int sum = 0;
			while (true) {
				if (s.empty()) {
					cout << "0";
					return 0;
				}

				int num = s.top();
				s.pop();
				if (num == -3) {
					if (sum == 0) s.push(3);
					else s.push(sum * 3);
					break;
				}
				else sum += num;
			}
		}
	}

	int ret = 0;
	while (!s.empty()) {
		if (s.top() == -2 || s.top() == -3) {
			cout << "0";
			return 0;
		}

		ret += s.top();
		s.pop();
	}
	cout << ret;

	return 0;
}