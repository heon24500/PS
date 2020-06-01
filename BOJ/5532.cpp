#include <iostream>
using namespace std;

int main() {
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    int korean = 0;
    int math = 0;

    if ((B % D) == 0) math = B / D;
    else math = (B / D) + 1;

    if ((A % C) == 0) korean = A / C;
    else korean = (A / C) + 1;

    int result = 0;

    if (korean > math) result = L - korean;
    else result = L - math;

    cout << result;

    return 0;
}