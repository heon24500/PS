#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	bool flag = false;
	while (n--) {
		string str;
		cin >> str;
		if (str == "anj") {
			flag = true;
			break;
		}
	}

	if (flag) cout << "构具;";
	else cout << "构具?";

	return 0;
}