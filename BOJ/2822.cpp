#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > score;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) {
		int num;
		cin >> num;
		score.push_back(make_pair(num, i + 1));
	}

	sort(score.begin(), score.end());

	int sum = 0, j = 0, ret[5] = {};
	for (int i = 7; i >= 3; i--) {
		sum += score[i].first;
		ret[j++] = score[i].second;
	}

	sort(ret, ret + 5);

	cout << sum << "\n";
	for (int i = 0; i < 5; i++) {
		cout << ret[i] << " ";
	}

	return 0;
}