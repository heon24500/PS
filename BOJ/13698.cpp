#include <iostream>
using namespace std;

int ball[4] = { 1, 0, 0, 2 };

void change(char ch) {
    if (ch == 'A') {
        int temp = ball[0];
        ball[0] = ball[1];
        ball[1] = temp;
    }
    else if (ch == 'B') {
        int temp = ball[0];
        ball[0] = ball[2];
        ball[2] = temp;
    }
    else if (ch == 'C') {
        int temp = ball[0];
        ball[0] = ball[3];
        ball[3] = temp;
    }
    else if (ch == 'D') {
        int temp = ball[1];
        ball[1] = ball[2];
        ball[2] = temp;
    }
    else if (ch == 'E') {
        int temp = ball[1];
        ball[1] = ball[3];
        ball[3] = temp;
    }
    else if (ch == 'F') {
        int temp = ball[2];
        ball[2] = ball[3];
        ball[3] = temp;
    }
}

int main() {
    char ch;
    while (scanf("%c", &ch) != EOF) {
        change(ch);
    }

    int pos1, pos2;
    for (int i = 0; i < 4; i++) {
        if (ball[i] == 1) pos1 = i;
        if (ball[i] == 2) pos2 = i;
    }

    printf("%d\n%d", pos1 + 1, pos2 + 1);
}