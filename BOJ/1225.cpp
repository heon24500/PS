#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string A, B;
	cin >> A >> B;

	long sum = 0;
	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++) {
			sum += (A[i] - '0') * (B[j] - '0');
		}
	}

	cout << sum;
}