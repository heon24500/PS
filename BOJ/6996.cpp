#include <iostream>
using namespace std;

bool isAnagrams(string s1, string s2) {
	if (s1.length() != s2.length()) return false;

	int cnt1[150] = { 0 }, cnt2[150] = { 0 };
	for (int i = 0; s1[i]; i++) {
		cnt1[s1[i]]++;
		cnt2[s2[i]]++;
	}

	for (int i = 'a'; i <= 'z'; i++) {
		if (cnt1[i] != cnt2[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (isAnagrams(s1, s2)) cout << s1 << " & " << s2 << " are anagrams.\n";
		else cout << s1 << " & " << s2 << " are NOT anagrams.\n";
	}

	return 0;
}