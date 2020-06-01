#include <iostream>
using namespace std;

int main() {
    while (true) {
        int year;
        scanf("%d", &year);

        if (year == 0) break;

        if (year < 1896) printf("%d No summer games\n", year);
        else if (year > 2020) {
            if ((year - 1896) % 4 == 0) printf("%d No city yet chosen\n", year);
            else printf("%d No summer games\n", year);
        }
        else {
            if ((year >= 1914 && year <= 1918) || (year >= 1939 && year <= 1945)) {
                if ((year - 1896) % 4 == 0) printf("%d Games cancelled\n", year);
                else printf("%d No summer games\n", year);
            }
            else {
                if ((year - 1896) % 4 == 0) printf("%d Summer Olympics\n", year);
                else printf("%d No summer games\n", year);
            }
        }
    }
}