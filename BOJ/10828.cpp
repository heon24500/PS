#include <iostream>
using namespace std;

class stack {
private:
	int num[10000];
	int idx = -1;

public:
	void push(int x) {
		num[++idx] = x;
	}

	int pop() {
		int ret = -1;
		if (idx >= 0) ret = num[idx--];
		return ret;
	}

	int size() {
		return idx + 1;
	}

	int empty() {
		if (idx == -1) return 1;
		else return 0;
	}

	int top() {
		int ret = -1;
		if (idx >= 0) ret = num[idx];
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack s;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;

			s.push(num);
		}
		else if (str == "top") cout << s.top() << "\n";
		else if (str == "size") cout << s.size() << "\n";
		else if (str == "empty") cout << s.empty() << "\n";
		else if (str == "pop") cout << s.pop() << "\n";
	}

	return 0;
}