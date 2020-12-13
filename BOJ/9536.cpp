#include <iostream>
#include <vector>
#include <string>
using namespace std;

string sound;
vector<string> animals;

string solve() {
	string str = sound;

	for (int i = 0; i < animals.size(); i++) {
		string temp;
		string now;
		for (int j = 0; str[j]; j++) {
			if (str[j] == ' ') {
				if (temp != animals[i]) {
					if (now.length() != 0) now += " ";
					now += temp;
				}
				temp = "";
			}
			else temp += str[j];
		}
		if (temp != animals[i]) {
			if (now.length() != 0) now += " ";
			now += temp;
		}
		str = now;
	}

	return str;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	getline(cin, sound);
	while (t--) {
		getline(cin, sound);
		while (true) {
			string str;
			getline(cin, str);
			if (str == "what does the fox say?") break;

			string s;
			int cnt = 0;
			for (int i = 0; str[i]; i++) {
				if (str[i] == ' ') cnt++;
				else if (cnt == 2) s += str[i];
			}
			animals.push_back(s);
		}
		cout << solve() << '\n';
	}

	return 0;
}