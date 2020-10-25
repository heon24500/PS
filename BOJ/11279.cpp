#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

void pop() {
	if (pq.empty()) {
		cout << "0\n";
		return;
	}

	cout << pq.top() << "\n";
	pq.pop();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		if (num == 0) pop();
		else pq.push(num);
	}

	return 0;
}