#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int n, ret;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	if (q.size() == 1) ret = 1;
	else {
		while (q.size() > 1) {
			q.pop();
			ret = q.front();
			q.pop();
			q.push(ret);
		}
	}

	cout << ret;

	return 0;
}