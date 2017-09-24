#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
    
    Date()
    {}
    
    Date(int day, int month, int year)
    : day(day),
    month(month),
    year(year)
    {}
    
    friend istream& operator >> (istream& is, Date& date);
};

istream& operator >> (istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}

int libraryFine(const Date& date, const Date& dueDate) {
    if (date.year > dueDate.year) {
        return 10000;
    }
    
    if (date.month > dueDate.month && date.year == dueDate.year) {
        return 500 * (date.month - dueDate.month);
    }
    
    if (date.day > dueDate.day && date.month == dueDate.month && date.year == dueDate.year) {
        return 15 * (date.day - dueDate.day);
    }
    
    return 0;
}

int main()
{
    Date date, dueDate;
    
    cin >> date >> dueDate;
    
    cout << libraryFine(date, dueDate) << endl;
    
    return 0;
}
