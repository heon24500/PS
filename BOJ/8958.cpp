#include <iostream>
#include <string>
using namespace std;

int main() {
	int testCase;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		string str;
		cin >> str;

		int sum = 0, num = 0, cnt = 0;
		num = str.size();

		for (int j = 0; j < num; j++) {
			if (str[j] == 'O') {
				cnt++;
			}
			else {
				cnt = 0;
			}

			sum += cnt;
		}

		cout << sum << endl;
	}



	return 0;
}