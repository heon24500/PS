#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N, c;
	vector<int> d;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int disk;
		cin >> disk;
		d.push_back(disk);
	}
	cin >> c;

	long ret = 0;
	for (int i = 0; i < d.size(); i++) {
		if (d[i] % c == 0) ret += (d[i] / c) * c;
		else ret += (d[i] / c + 1) * c;
	}

	cout << ret;
}