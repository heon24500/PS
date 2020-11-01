#include <iostream>
#include <vector>
using namespace std;

char dat[36];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++) dat[i] = i + '0';
	for (int i = 10; i < 36; i++) dat[i] = 'A' + i - 10;

	int n, b;
	cin >> n >> b;

	vector<char> v;
	while (n >= b) {
		v.push_back(dat[n % b]);
		n /= b;
	}
	if (n > 0) v.push_back(dat[n]);

	for (int i = v.size() - 1; i >= 0; i--) printf("%c", v[i]);

	return 0;
}