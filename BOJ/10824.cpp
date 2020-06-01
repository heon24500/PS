#include <iostream>
#include <string>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	string ab = to_string(a) + to_string(b);
	string cd = to_string(c) + to_string(d);

	long result = stol(ab) + stol(cd);
	printf("%ld", result);
}