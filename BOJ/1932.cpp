/* 1932. Á¤¼ö »ï°¢Çü */
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int N = 130000;
int arr[N], dp[N];

pii parents(int n)
{
	int left = 0, right = 0;
	if (n <= 1) return make_pair(left, right);

	int node = 1, before_node = 0, next_node = 0, cnt = 1;
	while (n >= next_node) {
		before_node = node;
		node += cnt;
		cnt++;
		next_node = node + cnt;
	}

	if (node != n) left = before_node + n - node - 1;
	if (next_node - 1 != n) right = before_node + n - node;
	return make_pair(left, right);
}

int main()
{
	int n;
	cin >> n;

	int cnt = 1, ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[cnt];

			pii p = parents(cnt);
			if (cnt <= 1) dp[cnt] = arr[cnt];
			else dp[cnt] = arr[cnt] + max(dp[p.first], dp[p.second]);

			if (ret < dp[cnt]) ret = dp[cnt];
			cnt++;
		}
	}

	cout << ret;

	return 0;
}