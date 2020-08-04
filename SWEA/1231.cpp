/* 1231. [S/W 문제해결 기본] 9일차 - 중위순회 */
#include <iostream>
using namespace std;

const int N = 101;
char tree[N];
int n;

void init() {
	for (int i = 0; i < N; i++) {
		tree[i] = NULL;
	}
	n = 0;
}

void inorder(int t)
{
	if (!tree[t]) return;

	inorder(t * 2);
	cout << tree[t];
	inorder(t * 2 + 1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 1; t <= 10; t++) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			cin >> tree[num];

			int tmp1, tmp2;
			if (i * 2 < n) cin >> tmp1 >> tmp2;
			else if (i * 2 == n) cin >> tmp1;
		}

		cout << "#" << t << " ";
		inorder(1);
		cout << '\n';
		init();
	}

	return 0;
}