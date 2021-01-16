#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;

	stack<char> s;
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'P') s.push('P');
		else {
			if (i < str.length() - 1 && str[i + 1] == 'P' && s.size() >= 2) {
				s.pop();
				s.pop();
			}
			else {
				cout << "NP";
				return 0;
			}
		}
	}

	if (s.size() <= 1) cout << "PPAP";
	else cout << "NP";

	return 0;
}