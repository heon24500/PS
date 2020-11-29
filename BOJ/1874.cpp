#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 1;
	stack<int> s;
	vector<char> ans;
	while (n--) {
		int num;
		cin >> num;
		while (i <= num) {
			s.push(i++);
			ans.push_back('+');
		}

		while (!s.empty() && num < s.top()) {
			ans.push_back('-');
			s.pop();
		}

		if (s.empty() || (!s.empty() && num > s.top())) {
			cout << "NO\n";
			return 0;
		}

		ans.push_back('-');
		s.pop();
	}

	for (auto el : ans) cout << el << '\n';

	return 0;
}