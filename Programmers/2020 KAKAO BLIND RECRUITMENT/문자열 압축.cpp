#include <string>
#include <vector>

using namespace std;

int min_len;

vector<string> slice(string s, int n) {
    vector<string> ret;
    for (int i = 0; i < s.size(); i += n) {
        int len = s.size() - i;
        if (len > n) len = n;
        ret.push_back(s.substr(i, len));
    }
    return ret;
}

void cntCompress(vector<string> v) {
    string str;
    int cnt = 1;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] == v[i + 1]) cnt++;
        else {
            if (cnt > 1) str += to_string(cnt);
            str += v[i];
            cnt = 1;
        }
        if (min_len < str.length()) return;
    }
    if (cnt > 1) str += to_string(cnt);
    str += v[v.size() - 1];
    if (min_len > str.length()) min_len = str.length();
}

void solve(string s) {
    for (int i = 1; i <= s.size() / 2; i++) {
        vector<string> v = slice(s, i);
        cntCompress(v);
    }
}

int solution(string s) {
    int answer = 0;
    min_len = s.size();
    solve(s);
    answer = min_len;
    return answer;
}