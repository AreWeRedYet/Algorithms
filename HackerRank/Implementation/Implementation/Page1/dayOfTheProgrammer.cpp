#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

enum class YearType {
    Julian,
    Gregorian
};

enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    Jun,
    July,
    August,
    September,
    October,
    November,
    December,
    Max
};

YearType getYearType(int year) {
    if (year <= 1917) {
        return YearType::Julian;
    }
    
    return YearType::Gregorian;
}

bool isLeapYear(int year) {
    switch (getYearType(year)) {
        case YearType::Julian:
            return year % 4 == 0;
        case YearType::Gregorian:
            return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        default:
            throw "Invalid year type";
    }
}

vector<int> daysInAYear(int year) {
    vector<int> monthToDay((int)Month::Max);
    
    monthToDay[Month::January] = 31 + (year == 1918 ? -13 : 0);
    monthToDay[Month::February] = 28 + (isLeapYear(year) ? 1 : 0);
    monthToDay[Month::March] = 31;
    monthToDay[Month::April] = 30;
    monthToDay[Month::May] = 31;
    monthToDay[Month::Jun] = 30;
    monthToDay[Month::July] = 31;
    monthToDay[Month::August] = 31;
    monthToDay[Month::September] = 30;
    monthToDay[Month::October] = 31;
    monthToDay[Month::November] = 30;
    monthToDay[Month::December] = 31;
    
    return monthToDay;
    
}

string formatString(int x)
{
    return x <= 9 ? '0' + to_string(x) : to_string(x);
}

string formatDate(int day, int month, int year) {
    return formatString(day) + "." + formatString(month) + "." + to_string(year);
}

string programmerDay(int year) {
    vector<int> monthToDay = daysInAYear(year);
    int programmerDay = 256;
    
    int dayIterator = 0;
    int month = 1;
    
    while (dayIterator + monthToDay[month] < programmerDay) {
        dayIterator += monthToDay[month];
        month++;
    }
    
    int day = programmerDay - dayIterator;
    
    return formatDate(day, month, year);
}



int main()
{
    int year;
    
    cin >> year;
    
    cout << programmerDay(year) << endl;
    
    return 0;
}
