
#include "Time.h"
#include <sstream>
#include <iomanip>

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

bool Time::isValid() const {
    return hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60;
}

std::string Time::to24() const {
    std::ostringstream oss; //output string stream, ostringstream come cout ma costruisce stringa in memoria
    oss << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setw(2) //setfill() sceglie il carattere di riempimento per l'eventuale seconda cifra
        << minute << ":" << std::setw(2) << second;  //setw() garantisce che siano stampati a 2 cifre
    return oss.str();
}
