/* 1224. [S/W 문제해결 기본] 6일차 - 계산기3 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<char> pos;
stack<char> op;
stack<int> res;
int n;

void Init() {
	pos.clear();
	while (!op.empty()) {
		op.pop();
	}
	while (!res.empty()) {
		res.pop();
	}
}

void Pop() {
	pos.push_back(op.top());
	op.pop();
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			char ch;
			cin >> ch;
			// 중위표기 -> 후위표기 변환
			if (ch == '+') {
				while (!op.empty()) {
					if (op.top() == '(') break;
					Pop();
				}
				op.push(ch);
			}
			else if (ch == '*') {
				if (op.top() == '*') Pop();
				op.push(ch);
			}
			else if (ch == '(') {
				op.push(ch);
			}
			else if (ch == ')') {
				while (op.top() != '(') {
					Pop();
				}
				op.pop();
			}
			else {
				pos.push_back(ch);
			}
		}

		// 후위표기식 계산
		for (int i = 0; i < pos.size(); i++) {
			if (pos[i] == '+') {
				int b = res.top();
				res.pop();
				int a = res.top();
				res.pop();

				res.push(a + b);
			}
			else if (pos[i] == '*') {
				int b = res.top();
				res.pop();
				int a = res.top();
				res.pop();

				res.push(a * b);
			}
			else {
				res.push(pos[i] - '0');
			}
		}

		cout << "#" << t + 1 << " " << res.top() << '\n';
		Init();
	}

	return 0;
}