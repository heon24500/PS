/* 1242. [S/W 문제해결 응용] 1일차 - 암호코드 스캔 */
#include <iostream>
#include <vector>
using namespace std;

const int N = 2001;
const int M = 501;
char mat[N][M];

int valid(vector<int> v)
{
	vector<int> result;
	for (int i = 0; i < v.size(); i += 4) {
		if (v[i] == 1) {
			if (v[i + 1] == 1) {
				if (v[i + 2] == 1) result.push_back(6);
				else if (v[i + 2] == 3) result.push_back(4);
			}
			else if (v[i + 1] == 2) {
				if (v[i + 2] == 1) result.push_back(8);
				else if (v[i + 2] == 3) result.push_back(5);
			}
			else if (v[i + 1] == 3) result.push_back(7);
			else if (v[i + 1] == 4) result.push_back(3);
		}
		else if (v[i] == 2) {
			if (v[i + 1] == 1) result.push_back(2);
			else if (v[i + 1] == 2) result.push_back(1);
		}
		else if (v[i] == 3) {
			if (v[i + 1] == 1) result.push_back(9);
			else if (v[i + 1] == 2) result.push_back(0);
		}
	}

	int odd = 0, even = 0, sum = result[result.size() - 1];
	for (int i = 0; i < result.size() - 1; i++) {
		if (i % 2 == 0) odd += result[i];
		else even += result[i];
		sum += result[i];
	}

	int ret = odd * 3 + even + result[result.size() - 1];
	if (ret % 10 == 0) return sum;
	else return 0;
}

vector<int> digitSize(string str)
{
	vector<int> temp;
	char before = '2';
	int cnt = 0, min_cnt = 500;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != before) {
			if (i != 0) {
				temp.push_back(cnt);
				if (min_cnt > cnt) min_cnt = cnt;
			}
			before = str[i];
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	temp.push_back(cnt);

	vector<int> ret;
	for (int i = 0; i < temp.size(); i++) {
		ret.push_back(temp[i] / min_cnt);
	}
	return ret;
}

string toDigit(string str)
{
	//cout << "원본 : " << str << '\n';
	string ret;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '0':
			ret += "0000";
			break;
		case '1':
			ret += "0001";
			break;
		case '2':
			ret += "0010";
			break;
		case '3':
			ret += "0011";
			break;
		case '4':
			ret += "0100";
			break;
		case '5':
			ret += "0101";
			break;
		case '6':
			ret += "0110";
			break;
		case '7':
			ret += "0111";
			break;
		case '8':
			ret += "1000";
			break;
		case '9':
			ret += "1001";
			break;
		case 'A':
			ret += "1010";
			break;
		case 'B':
			ret += "1011";
			break;
		case 'C':
			ret += "1100";
			break;
		case 'D':
			ret += "1101";
			break;
		case 'E':
			ret += "1110";
			break;
		case 'F':
			ret += "1111";
			break;
		}
	}
	int idx = ret.length() - 1;
	while (ret[idx--] == '0') {}
	ret.erase(idx + 2, ret.length() - 1);
	idx = 0;
	while (ret[idx++] == '0') {}
	ret.erase(0, idx - 1);
	
	while (ret.length() % 56 != 0) {
		ret = "0" + ret;
	}
	//cout << "변환 : " << ret << '\n';
	//cout << "길이 : " << ret.length() << '\n';
	vector<int> sz = digitSize(ret);
	for (int i = 0; i < sz.size(); i++) {
		//cout << sz[i];
	}
	//cout << '\n';
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "[Test case #" << tc << "]\n";
		int n, m;
		cin >> n >> m;

		bool flag = false;
		int y = 0, src_x = 0, dest_x = 0;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			string str;
			int y = 0, src_x = 0, dest_x = 0;
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];

				if (mat[i][j] != '0' && (i == 0 || (i != 0 && mat[i - 1][j] == '0'))) {
					if (y == 0) y = i;
					if (src_x == 0) src_x = j;
					else dest_x = j;
				}
			}
			if (y != 0) {
				for (int j = src_x; j <= dest_x; j++) {
					str += mat[y][j];
				}
			}
			if (str.length() != 0) {
				string str1 = toDigit(str);
				vector<int> v = digitSize(str1);
				ret += valid(v);
			}
		}
		cout << ret << '\n';
	}


	return 0;
}