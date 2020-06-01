#include <iostream>
#include <vector>
using namespace std;

long sum(vector<int>& a) {
	long ret = 0;
	for (int i = 0; i < a.size(); i++) {
		ret += a[i];
	}

	return ret;
}