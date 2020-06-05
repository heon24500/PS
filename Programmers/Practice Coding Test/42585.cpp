#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    char b_ch = arrangement[0];
    s.push(b_ch);
    for (int i = 1; i < arrangement.length(); i++) {
        char ch = arrangement[i];
        if (ch == '(') s.push(ch);
        else {
            s.pop();
            if (b_ch == ')') answer++;
            else answer += s.size();
        }
        b_ch = ch;
    }

    return answer;
}