#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n + m; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}