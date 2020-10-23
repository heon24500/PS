#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (int i = 0; number[i]; i++) {
        if (k == 0) {
            answer += number.substr(i);
            break;
        }
        if (number.length() - i == k) break;

        bool flag = true;
        char num1 = number[i];
        for (int j = i + 1; j <= i + k; j++) {
            char num2 = number[j];
            if (num1 < num2) {
                flag = false;
                break;
            }
        }
        if (flag) answer += num1;
        else k--;
    }

    return answer;
}