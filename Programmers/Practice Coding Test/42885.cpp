#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[50000];

int solution(vector<int> people, int limit) {
    int answer = 0;
    int idx = 0;
    sort(people.begin(), people.end());
    int len = people.size();
    for (int i = len - 1; i >= 0; i--) {
        if (check[i]) continue;
        check[i] = true;
        int weight = people[i];
        if (weight + people[idx] <= limit) check[idx++] = true;
        answer++;
    }

    return answer;
}