#include <iostream>
using namespace std;

int dat[150];

int main() {
	string s;
	cin >> s;
	for (int i = 0; s[i]; i++) dat[s[i]]++;
	for (int i = 'a'; i <= 'z'; i++) cout << dat[i] << ' ';

	return 0;
}