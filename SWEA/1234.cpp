/* 1234. [S/W 문제해결 기본] 10일차 - 비밀번호 */
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> back;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		int len;
		cin >> len;
		for (int i = 0; i < len; i++) {
			char ch;
			cin >> ch;
			int num = ch - '0';
			if (!s.empty() && s.top() == num) s.pop();
			else s.push(num);
		}

		cout << "#" << t + 1 << " ";
		while (!s.empty()) {
			back.push(s.top());
			s.pop();
		}
		while(!back.empty()) {
			cout << back.top();
			back.pop();
		}
		cout << '\n';
	}

	return 0;
}