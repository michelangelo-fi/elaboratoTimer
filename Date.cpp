//
// Created by michelangelo on 28/04/25.
//

#include "Date.h"
#include <sstream>
#include <iomanip>

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::isLeap() const {  //controllo se è bisestile
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isValid() const {
    if (year < 0 || month < 1 || month > 12) return false;
    static const int dim[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = dim[month - 1];
    if (month == 2 && isLeap()) maxDay = 29;
    return day >= 1 && day <= maxDay;
}

std::string Date::toIso() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << year << "-"
        << std::setw(2) << month << "-" << std::setw(2) << day;
    return oss.str();
}