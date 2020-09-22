#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str, ret;
	cin >> str;

	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') ret += str[i];
		if (str[i] == '+' || str[i] == '-') {
			while (!s.empty()) {
				if (s.top() == '(') break;
				ret += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		if (str[i] == '*' || str[i] == '/') {
			while (!s.empty()) {
				if (s.top() == '(' || s.top() == '+' || s.top() == '-') break;
				ret += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		if (str[i] == '(') s.push(str[i]);
		if (str[i] == ')') {
			while (s.top() != '(') {
				ret += s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty()) {
		ret += s.top();
		s.pop();
	}
	cout << ret;

	return 0;
}