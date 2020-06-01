#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N;
	string names[150];
	char fam[26];
	for (int i = 0; i < 26; i++) {
		fam[i] = 0;
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> names[i];
		fam[names[i][0] - 'a']++;
	}

	bool flag = false;
	for (int i = 0; i < 26; i++) {
		if (fam[i] >= 5) {
			flag = true;
			char ch = i + 'a';
			cout << ch;
		}
	}

	if (!flag) cout << "PREDAJA";
}