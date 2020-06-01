#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<char> str;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        str.push_back(ch);
    }

    while (N > 1) {
        vector<char> temp = str;
        temp.pop_back();
        temp.pop_back();

        if (str[N - 2] == 'A') {
            if (str[N - 1] == 'A') temp.push_back('A');
            else if (str[N - 1] == 'G') temp.push_back('C');
            else if (str[N - 1] == 'C') temp.push_back('A');
            else temp.push_back('G');
        }
        else if (str[N - 2] == 'G') {
            if (str[N - 1] == 'A') temp.push_back('C');
            else if (str[N - 1] == 'G') temp.push_back('G');
            else if (str[N - 1] == 'C') temp.push_back('T');
            else temp.push_back('A');
        }
        else if (str[N - 2] == 'C') {
            if (str[N - 1] == 'A') temp.push_back('A');
            else if (str[N - 1] == 'G') temp.push_back('T');
            else if (str[N - 1] == 'C') temp.push_back('C');
            else temp.push_back('G');
        }
        else if (str[N - 2] == 'T') {
            if (str[N - 1] == 'A') temp.push_back('G');
            else if (str[N - 1] == 'G') temp.push_back('A');
            else if (str[N - 1] == 'C') temp.push_back('G');
            else temp.push_back('T');
        }

        str = temp;
        N--;
    }

    cout << str[0];
}