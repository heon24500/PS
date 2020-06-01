#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int strLen = str.size();
	int chFlag = 0;

	if (strLen < 2) {
		cout << strLen << endl;
	}
	else {
		char beforeWord = str[1];
		char beforeWord2 = str[0];
		int manyWords = 2;

		if (beforeWord == '=') {
			if (beforeWord2 == 'c') {
				manyWords--;
			}
			else if (beforeWord2 == 's') {
				manyWords--;
			}
			else if (beforeWord2 == 'z') {
				manyWords--;
			}
		}
		else if (beforeWord == '-') {
			if (beforeWord2 == 'c') {
				manyWords--;
			}
			else if (beforeWord2 == 'd') {
				manyWords--;
			}
		}
		else if (beforeWord == 'j') {
			if (beforeWord2 == 'l') {
				manyWords--;
			}
			else if (beforeWord2 == 'n') {
				manyWords--;
			}
		}

		for (int i = 2; i < strLen; i++) {
			manyWords++;

			if (str[i] == '=') {
				if (beforeWord == 'c') {
					manyWords--;
				}
				else if (beforeWord == 's') {
					manyWords--;
				}
				else if (beforeWord == 'z') {
					if (beforeWord2 == 'd') {
						manyWords -= 2;
					}
					else {
						manyWords--;
					}
				}
			}
			else if (str[i] == '-') {
				if (beforeWord == 'c') {
					manyWords--;
				}
				else if (beforeWord == 'd') {
					manyWords--;
				}
			}
			else if (str[i] == 'j') {
				if (beforeWord == 'l') {
					manyWords--;
				}
				else if (beforeWord == 'n') {
					manyWords--;
				}
			}

			beforeWord2 = beforeWord;
			beforeWord = str[i];
		}

		cout << manyWords << endl;
	}

	return 0;
}