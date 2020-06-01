#include <iostream>
using namespace std;

int main() {
	string str;

	for (int i = 0; i < 100; i++) {
		char str[1000];

		cin.getline(str, 1000, '\n');
		cout << str << endl;
	}

	return 0;
}