#include <iostream>
#include <queue>
using namespace std;

deque<int> parseArr(string str) {
	deque<int> ret;
	int num = 0;

	for (int i = 1; str[i]; i++) {
		if (str[i] == ']' || str[i] == ',') {
			if (num <= 0) continue;
			ret.push_back(num);
			num = 0;
		}
		else num = (num * 10) + str[i] - '0';
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string cmd, str;
		int n;
		bool dir = false; // false: 정방향, true: 역방향
		cin >> cmd >> n >> str;

		deque<int> arr = parseArr(str);

		bool isFinish = true;
		for (int i = 0; cmd[i]; i++) {
			if (cmd[i] == 'R') dir = !dir;
			if (cmd[i] == 'D') {
				if (arr.empty()) {
					isFinish = false;
					break;
				}
				else {
					if (dir) arr.pop_back();
					else arr.pop_front();
				}
			}
		}

		if (isFinish) {
			cout << "[";
			bool isFirst = true;
			while (!arr.empty()) {
				if (!isFirst) cout << ",";
				isFirst = false;

				if (dir) {
					cout << arr.back();
					arr.pop_back();
				}
				else {
					cout << arr.front();
					arr.pop_front();
				}
			}
			cout << "]\n";
		}
		else cout << "error\n";
	}

	return 0;
}