#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, val = 10, idx = 1;
	cin >> n;
	while (true) {
		if (n <= val) break;

		string str = to_string(n);
		int partition = str.length() - idx;
		string str_n1 = str.substr(0, partition);
		string str_n2 = str.substr(partition, idx);

		int int_n1 = stoi(str_n1);
		if (str_n2[0] >= '5') int_n1++;
		str_n2[0] = '0';
		str_n1 = to_string(int_n1);
		str = str_n1 + str_n2;
		n = stoi(str);

		idx++;
		val *= 10;
	}
	cout << n;

	return 0;
}