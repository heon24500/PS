#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;

	vector<string> v;
	int len = str.length();
	for (int i = 0; i < len; i++) v.push_back(str.substr(i));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';

	return 0;
}