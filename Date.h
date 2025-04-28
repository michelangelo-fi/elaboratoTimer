//
// Created by michelangelo on 28/04/25.
//

#ifndef ELABORATOTIMER_DATE_H
#define ELABORATOTIMER_DATE_H
#include <string>

class Date {
public:
    Date(int d = 1, int m = 1, int y = 1970);
    bool isValid() const;
    std::string toIso() const; // Y-M-D
private:
    bool isLeap() const;
    int day, month, year;
};


#endif //ELABORATOTIMER_DATE_H
