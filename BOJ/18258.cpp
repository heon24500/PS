#include <iostream>
using namespace std;

const int N = 2000000;
int q[N];
int front, rear;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			cin >> q[rear++];
		}
		else if (str == "pop") {
			if (front == rear) cout << "-1\n";
			else cout << q[front++] << '\n';
		}
		else if (str == "size") {
			cout << rear - front << '\n';
		}
		else if (str == "empty") {
			if (front == rear) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "front") {
			if (front == rear) cout << "-1\n";
			else cout << q[front] << '\n';
		}
		else if (str == "back") {
			if (front == rear) cout << "-1\n";
			else cout << q[rear - 1] << '\n';
		}
	}

	return 0;
}