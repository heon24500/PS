#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string str;
		getline(cin, str);
		if (str == "EOI") break;
		for (int i = 0; str[i]; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
		}
		if (str.find("nemo") != string::npos) cout << "Found\n";
		else cout << "Missing\n";
	}

	return 0;
}