#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;

		stack<char> s;
		for (int i = 0; str[i]; i++) {
			if (s.empty()) s.push(str[i]);
			else {
				if (s.top() == str[i]) s.pop();
				else s.push(str[i]);
			}
		}

		if (s.empty()) ans++;
	}
	cout << ans;

	return 0;
}