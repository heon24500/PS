#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	deque<int> dq;
	for (int i = 1; i <= n; i++) dq.push_back(i);

	cout << "<";
	while (!dq.empty()) {
		for (int i = 0; i < k - 1; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << dq.front();
		dq.pop_front();
		if (!dq.empty()) cout << ", ";
	}
	cout << ">\n";

	return 0;
}
