#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    string months[12] = {"January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int month, year;
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    // Leap year check
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        daysInMonth[1] = 29;

    // Calculate total days since 1 Jan 1900
    int totalDays = 0;

    // Add days for all full years before the given year
    for (int y = 1900; y < year; y++)
        totalDays += 365 + ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0) ? 1 : 0);

    // Add days for months before the given month in the same year
    for (int m = 0; m < month - 1; m++)
        totalDays += daysInMonth[m];

    // Add 1 for the first day of the month
    totalDays += 1;

    int startDay = totalDays % 7; // 0=Sunday, 1=Monday, ...

    // Print header
    cout << "\n     " << months[month - 1] << " " << year << endl;
    for (int i = 0; i < 7; i++)
        cout << days[i] << " ";
    cout << endl;

    // Leading spaces
    for (int i = 0; i < startDay; i++)
        cout << "    ";

    // Print dates
    for (int date = 1; date <= daysInMonth[month - 1]; date++)
    {
        cout << setw(3) << date << " ";
        if ((date + startDay) % 7 == 0)
            cout << endl;
    }
    cout << endl;
    return 0;
}
