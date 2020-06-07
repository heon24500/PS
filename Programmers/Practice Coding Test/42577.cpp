#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size(); i++) {
        string now = phone_book[i];
        for (int j = 0; j < phone_book.size(); j++) {
            if (i == j || now.length() > phone_book[j].length()) continue;
            string cmp = phone_book[j].substr(0, now.length());
            if (now == cmp) return false;
        }
    }
    return true;
}