#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	vector<char> v;
	for (int i = 0; str[i]; i++) v.push_back(str[i]);

	if (next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < v.size(); i++) cout << v[i];
	}
	else cout << "0";

	return 0;
}