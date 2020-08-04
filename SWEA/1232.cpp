/* 1232. [S/W 문제해결 기본] 9일차 - 사칙연산 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int N = 1001;
int tree[N][2];
string ops[N];
stack<int> s;

void init()
{
	for (int i = 0; i < N; i++) {
		tree[i][0] = 0;
		tree[i][1] = 0;
		ops[i] = "";
	}

	while (!s.empty()) {
		s.pop();
	}
}

bool isOperator(string str)
{
	char ch = str[0];
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
	else return false;
}

int calc(string str)
{
	char ch = str[0];
	int b = s.top();
	s.pop();
	int a = s.top();
	s.pop();

	if (ch == '+') {
		return a + b;
	}
	else if (ch == '-') {
		return a - b;
	}
	else if (ch == '*') {
		return a * b;
	}
	else if (ch == '/') {
		return a / b;
	}
}

void postorder(int t)
{
	if (t == 0) return;

	postorder(tree[t][0]);
	postorder(tree[t][1]);
	string str = ops[t];
	int result;
	if (isOperator(str)) result = calc(str);
	else result = stoi(str);
	s.push(result);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			cin >> ops[num];
			if (isOperator(ops[num])) {
				cin >> tree[num][0] >> tree[num][1];
			}
		}

		postorder(1);
		cout << "#" << t << " " << s.top() << '\n';
		init();
	}

	return 0;
}