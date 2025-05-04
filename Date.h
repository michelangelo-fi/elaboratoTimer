

#ifndef ELABORATOTIMER_DATE_H
#define ELABORATOTIMER_DATE_H

#include <string>

class Date {
public:
    Date(int d = 1, int m = 1, int y = 1970);

    std::string toIso() const; // Y-M-D

    bool isLeap() const;

private:
    bool isValid() const;

    int day, month, year;
};


#endif //ELABORATOTIMER_DATE_H
