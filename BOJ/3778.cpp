#include <iostream>
#include <string>
using namespace std;

int anagramDistance(string s1, string s2) {
	int cnt1[150] = { 0 }, cnt2[150] = { 0 };
	int ret = 0;
	for (int i = 0; i < s1.length(); i++) cnt1[s1[i]]++;
	for (int i = 0; i < s2.length(); i++) cnt2[s2[i]]++;
	for (int i = 'a'; i <= 'z'; i++) ret += abs(cnt1[i] - cnt2[i]);
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string temp;
	getline(cin, temp);

	for (int i = 1; i <= n; i++) {
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		cout << "Case #" << i << ": " << anagramDistance(s1, s2) << '\n';
	}

	return 0;
}