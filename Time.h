
#ifndef ELABORATOTIMER_TIME_H
#define ELABORATOTIMER_TIME_H

#include <string>

class Time {
public:
   explicit Time(int h = 0, int m = 0, int s = 0);

    std::string to24() const; // HH:MM:SS
private:
    bool isValid() const;

    int hour, minute, second;
};


#endif //ELABORATOTIMER_TIME_H
