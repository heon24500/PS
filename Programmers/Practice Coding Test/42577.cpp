#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    int len = phone_book.size();
    for (int i = 0; i < len; i++) {
        int len1 = phone_book[i].length();
        for (int j = 0; j < len; j++) {
            if (i == j) continue;
            int len2 = phone_book[j].length();
            if (len1 > len2 || (len1 == len2 && phone_book[i] != phone_book[j])) continue;
            if (phone_book[i] == phone_book[j].substr(0, len1)) return false;
        }
    }

    return true;
}