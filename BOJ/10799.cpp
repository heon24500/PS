#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;

	stack<char> s;
	int ans = 0;
	for (int i = 0; str[i]; i++) {
		if (i != 0 && str[i - 1] == '(' && str[i] == ')') {
			s.pop();
			ans += s.size();
		}
		else {
			if (str[i] == '(') s.push('(');
			else {
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}