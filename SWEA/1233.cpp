/* 1233. [S/W 문제해결 기본] 9일차 - 사칙연산 유효성 검사 */
#include <iostream>
using namespace std;

const int N = 201;
int tree[N][2];
char ch[N];

void init()
{
	for (int i = 0; i < N; i++) {
		tree[i][0] = tree[i][1] = 0;
		ch[i] = NULL;
	}
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
	else return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		int n;
		cin >> n;

		int ret = 1;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			cin >> ch[num];

			if (i * 2 < n) {
				cin >> tree[num][0] >> tree[num][1];
				if (!isOperator(ch[num])) ret = 0;
			}
			else if (i * 2 == n) {
				cin >> tree[num][0];
				if (!isOperator(ch[num])) ret = 0;
			}
			else {
				if (isOperator(ch[num])) ret = 0;
			}
		}

		cout << "#" << t << " " << ret << '\n';
	}

	return 0;
}