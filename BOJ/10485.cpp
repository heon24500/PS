#include <iostream>
using namespace std;

int my_queue[10000];
int front = 0, rear = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			my_queue[rear++] = num;
		}
		else if (str == "pop") {
			if (front == rear) cout << "-1\n";
			else cout << my_queue[front++] << '\n';
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
			else cout << my_queue[front] << '\n';
		}
		else if (str == "back") {
			if (front == rear) cout << "-1\n";
			else cout << my_queue[rear - 1] << '\n';
		}
	}

	return 0;
}