#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        int a = commands[i][0] - 1;
        int b = commands[i][1] - 1;
        int k = commands[i][2] - 1;

        vector<int> v;
        for (int j = a; j <= b; j++) v.push_back(array[j]);
        sort(v.begin(), v.end());
        answer.push_back(v[k]);
    }
    return answer;
}