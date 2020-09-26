#include <iostream>
#include <deque>
using namespace std;

deque<char> dq[5];

void move(int n, int d) {
	if (d == 1) {
		char ch = dq[n].back();
		dq[n].pop_back();
		dq[n].push_front(ch);
	}
	else {
		char ch = dq[n].front();
		dq[n].pop_front();
		dq[n].push_back(ch);
	}
}

void solve(int n, int d) {
	if (n == 1) {
		if (dq[1].at(2) != dq[2].at(6)) {
			if (dq[2].at(2) != dq[3].at(6)) {
				if (dq[3].at(2) != dq[4].at(6)) move(4, -d);
				move(3, d);
			}
			move(2, -d);
		}
		move(1, d);
	}
	if (n == 2) {
		if (dq[2].at(6) != dq[1].at(2)) move(1, -d);
		if (dq[2].at(2) != dq[3].at(6)) {
			if (dq[3].at(2) != dq[4].at(6)) move(4, d);
			move(3, -d);
		}
		move(2, d);
	}
	if (n == 3) {
		if (dq[3].at(6) != dq[2].at(2)) {
			if (dq[2].at(6) != dq[1].at(2)) move(1, d);
			move(2, -d);
		}
		if (dq[3].at(2) != dq[4].at(6)) move(4, -d);
		move(3, d);
	}
	if (n == 4) {
		if (dq[4].at(6) != dq[3].at(2)) {
			if (dq[3].at(6) != dq[2].at(2)) {
				if (dq[2].at(6) != dq[1].at(2)) move(1, -d);
				move(2, d);
			}
			move(3, -d);
		}
		move(4, d);
	}
}

int main() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			char ch;
			cin >> ch;
			dq[i].push_back(ch);
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n, d;
		cin >> n >> d;
		solve(n, d);
	}

	int sum = 0, ret = 1;
	for (int i = 1; i <= 4; i++) {
		if (dq[i].front() == '1') sum += ret;
		ret *= 2;
	}
	cout << sum;

	return 0;
}