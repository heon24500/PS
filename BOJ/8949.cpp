#include <iostream>
#include <vector>
using namespace std;

char dat[36];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	vector<int> v;
	while (true) {
		if (a > 0 && b > 0) v.push_back(a % 10 + b % 10);
		else if (a > 0) v.push_back(a % 10);
		else if (b > 0) v.push_back(b % 10);
		else break;

		a /= 10;
		b /= 10;
	}

	for (int i = v.size() - 1; i >= 0; i--) printf("%d", v[i]);

	return 0;
}