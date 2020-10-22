#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++) m[clothes[i][1]]++;
    for (auto iter = m.begin(); iter != m.end(); iter++) answer *= iter->second + 1;
    answer--;
    return answer;
}