#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int height = v[v.size() - 1], cnt = 1;
	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] > height) {
			height = v[i];
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}