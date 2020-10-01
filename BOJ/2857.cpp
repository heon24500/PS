#include <iostream>
#include <vector>
using namespace std;

bool isFbi(string str) {
	int len = str.length();
	for (int i = 0; i < len - 2; i++) {
		if (str[i] == 'F' && str[i + 1] == 'B' && str[i + 2] == 'I') return true;
	}
	return false;
}

int main() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;
		if (isFbi(str)) v.push_back(i + 1);
	}

	if (v.empty()) cout << "HE GOT AWAY!";
	else {
		int len = v.size();
		for (int i = 0; i < len; i++) {
			cout << v[i] << " ";
		}
	}

	return 0;
}