#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string color[3];
	long long ret = 0, val = 10;
	for (int i = 0; i < 3; i++) {
		cin >> color[i];
		if (color[i] == "brown") {
			if (i < 2) ret += 1 * val;
			else ret *= 10;
		}
		else if (color[i] == "red") {
			if (i < 2) ret += 2 * val;
			else ret *= 100;
		}
		else if (color[i] == "orange") {
			if (i < 2) ret += 3 * val;
			else ret *= 1000;
		}
		else if (color[i] == "yellow") {
			if (i < 2) ret += 4 * val;
			else ret *= 10000;
		}
		else if (color[i] == "green") {
			if (i < 2) ret += 5 * val;
			else ret *= 100000;
		}
		else if (color[i] == "blue") {
			if (i < 2) ret += 6 * val;
			else ret *= 1000000;
		}
		else if (color[i] == "violet") {
			if (i < 2) ret += 7 * val;
			else ret *= 10000000;
		}
		else if (color[i] == "grey") {
			if (i < 2) ret += 8 * val;
			else ret *= 100000000;
		}
		else if (color[i] == "white") {
			if (i < 2) ret += 9 * val;
			else ret *= 1000000000;
		}

		val /= 10;
	}

	cout << ret;
}