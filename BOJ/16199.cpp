#include <iostream>
using namespace std;

int main() {
    int b_year, b_month, b_day;
    int year, month, day;
    int m_age, s_age, y_age;

    cin >> b_year >> b_month >> b_day;
    cin >> year >> month >> day;

    y_age = year - b_year;
    s_age = y_age + 1;

    if (year > b_year) {
        if (month > b_month) m_age = year - b_year;
        else if (month == b_month) {
            if (day >= b_day) m_age = year - b_year;
            else m_age = year - b_year - 1;
        }
        else m_age = year - b_year - 1;
    }
    else m_age = year - b_year;

    cout << m_age << endl << s_age << endl << y_age;

    return 0;
}