#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	stack<double> s;
	for (int i = 0; str[i]; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') s.push(v[str[i] - 'A']);
		else {
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();
			if (str[i] == '+') s.push(num1 + num2);
			if (str[i] == '-') s.push(num1 - num2);
			if (str[i] == '*') s.push(num1 * num2);
			if (str[i] == '/') s.push(num1 / num2);
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << s.top();

	return 0;
}