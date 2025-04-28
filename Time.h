//
// Created by michelangelo on 28/04/25.
//

#ifndef ELABORATOTIMER_TIME_H
#define ELABORATOTIMER_TIME_H

#include <string>


class Time {
public:
    Time(int h = 0, int m = 0, int s = 0);
    bool isValid() const;
    std::string to24() const; // HH:MM:SS
private:
    int hour, minute, second;
};


#endif //ELABORATOTIMER_TIME_H
