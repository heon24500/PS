#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long width, height, diagonal;
    int widthRatio, heightRatio;
    cin >> diagonal >> heightRatio >> widthRatio;

    height = (diagonal * heightRatio) / sqrt((heightRatio * heightRatio) + (widthRatio * widthRatio));
    width = (diagonal * widthRatio) / sqrt((heightRatio * heightRatio) + (widthRatio * widthRatio));

    cout << height << " " << width;

    return 0;
}