#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector<char> &ch, vector<int> &v) {
	for (int i = 0; i < ch.size(); i++) {
		if (ch[i] == '<' && v[i] > v[i + 1]) return false;
		if (ch[i] == '>' && v[i] < v[i + 1]) return false;
	}
	return true;
}

int main() {
	int k;
	cin >> k;
	vector<char> c(k);
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}

	vector<int> maxi(k+1), mini(k+1);
	for (int i = 0; i <= k; i++) {
		maxi[i] = 9 - i;
		mini[i] = i;
	}

	do {
		if (check(c, maxi)) break;
	} while (prev_permutation(maxi.begin(), maxi.end()));
	do {
		if (check(c, mini)) break;
	} while (next_permutation(mini.begin(), mini.end()));
	
	for (int i = 0; i < maxi.size(); i++) {
		cout << maxi[i];
	}
	cout << '\n';
	for (int i = 0; i < mini.size(); i++) {
		cout << mini[i];
	}
	cout << '\n';

	return 0;
}