#include <iostream>
using namespace std;

void printAnd(string a, string b) {
	for (int i = 0; a[i]; i++) {
		if (a[i] == '1' && b[i] == '1') cout << 1;
		else cout << 0;
	}
	cout << '\n';
}

void printOr(string a, string b) {
	for (int i = 0; a[i]; i++) {
		if (a[i] == '1' || b[i] == '1') cout << 1;
		else cout << 0;
	}
	cout << '\n';
}

void printXor(string a, string b) {
	for (int i = 0; a[i]; i++) {
		if (a[i] != b[i]) cout << 1;
		else cout << 0;
	}
	cout << '\n';
}
void printNot(string a) {
	for (int i = 0; a[i]; i++) {
		if (a[i] == '1') cout << 0;
		else cout << 1;
	}
	cout << '\n';
}

int main() {
	string a, b;
	cin >> a >> b;

	printAnd(a, b);
	printOr(a, b);
	printXor(a, b);
	printNot(a);
	printNot(b);

	return 0;
}