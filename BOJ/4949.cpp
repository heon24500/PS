#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		bool flag = true;
		stack<char> s;
		string str;
		getline(cin, str);
		if (str[0] == '.') break;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') s.push(str[i]);
			else if (str[i] == ')') {
				if (i == 0) {
					flag = false;
					break;
				}

				if (s.size() != 0 && s.top() == '(') s.pop();
				else {
					flag = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (i == 0) {
					flag = false;
					break;
				}

				if (s.size() != 0 && s.top() == '[') s.pop();
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag && s.size() == 0) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}