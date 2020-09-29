#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<char> > v;
	string str;
	int k;
	cin >> k >> str;

	int len = str.length();
	bool flag = 0;
	vector<char> temp(k);
	for (int i = 0; i < len; i++) {
		if (i % k == 0) {
			flag = !flag;
			if (i != 0) v.push_back(temp);
		}

		if (flag) temp[i % k] = str[i];
		else temp[k - i % k - 1] = str[i];
	}
	v.push_back(temp);

	len = v.size();
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < len; j++) {
			cout << v[j][i];
		}
	}

	return 0;
}