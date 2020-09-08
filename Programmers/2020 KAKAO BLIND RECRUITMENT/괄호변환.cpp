#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') s.push(str[i]);
        else {
            if (!s.empty() && s.top() == '(') s.pop();
            else return false;
        }
    }
    if (s.empty()) return true;
    else return false;
}

string solve(string str) {
    // 1단계
    if (str == "") return str;

    // 2단계
    int cnt_left = 0, cnt_right = 0, idx = 0;
    while (true) {
        if (str[idx++] == '(') cnt_left++;
        else cnt_right++;

        if (cnt_left == cnt_right) break;
    }
    string u, v;
    for (int i = 0; i < str.length(); i++) {
        if (i < idx) u += str[i];
        else v += str[i];
    }

    // 3단계
    if (isCorrect(u)) return u + solve(v);
    else {
        // 4단계
        string ret = "(" + solve(v) + ")";
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') ret += ')';
            else ret += '(';
        }
        return ret;
    }
}

string solution(string p) {
    string answer = solve(p);
    return answer;
}