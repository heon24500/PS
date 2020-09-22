#include <iostream>
using namespace std;

int cnt[100];
int avg;

int main() {
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		avg += num / 10;
		cnt[num / 10]++;
	}

	int ret = 0;
	for (int i = 0; i < 100; i++) {
		if (cnt[ret] < cnt[i]) ret = i;
	}

	cout << avg << '\n' << ret * 10 << '\n';

	return 0;
}