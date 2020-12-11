#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    if (*max_element(numbers.begin(), numbers.end()) == 0) return "0";

    for (auto number : numbers) v.push_back(to_string(number) + to_string(number) + to_string(number));
    sort(v.rbegin(), v.rend());
    for (auto u : v) answer += u.substr(0, u.length() / 3);

    return answer;
}