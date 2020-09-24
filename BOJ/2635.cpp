#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> ret;
	for (int i = 0; i <= n; i++) {
		vector<int> now;
		int a = n;
		int b = i;
		now.push_back(a);
		now.push_back(b);
		while (a - b >= 0) {
			int temp = b;
			b = a - b;
			a = temp;
			now.push_back(b);
		}
		if (ret.size() < now.size()) ret = now;
	}

	cout << ret.size() << '\n';
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}