#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);

	int flag = 0;
	for (int i = 0; str[i]; i++) {
		if (flag == 0 && str[i] == 'U') flag++;
		else if (flag == 1 && str[i] == 'C') flag++;
		else if (flag == 2 && str[i] == 'P') flag++;
		else if (flag == 3 && str[i] == 'C') flag++;
		if (flag == 4) break;
	}
	if (flag == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";

	return 0;
}