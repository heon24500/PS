/* 1218. [S/W ¹®Á¦ÇØ°á ±âº»] 4ÀÏÂ÷ - °ýÈ£ Â¦Áþ±â */
#include <iostream>
#include <stack>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int len;
		cin >> len;

		stack<char> s;
		bool flag = false;
		for (int i = 0; i < len; i++) {
			char ch;
			cin >> ch;
			if (ch == '(' || ch == '[' || ch == '{' || ch == '<') s.push(ch);
			else if (ch == ')') {
				if (s.top() == '(') s.pop();
				else flag = true;
			}
			else if (ch == ']') {
				if (s.top() == '[') s.pop();
				else flag = true;
			}
			else if (ch == '}') {
				if (s.top() == '{') s.pop();
				else flag = true;
			}
			else if (ch == '>') {
				if (s.top() == '<') s.pop();
				else flag = true;
			}
		}

		cout << "#" << t + 1 << " ";
		if (flag) cout << "0\n";
		else cout << "1\n";
	}

	return 0;
}