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

	if (flag) cout << "����;";
	else cout << "����?";

	return 0;
}