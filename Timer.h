//
// Created by michelangelo on 28/04/25.
//

#ifndef ELABORATOTIMER_TIMER_H
#define ELABORATOTIMER_TIMER_H
#include <functional>
#include <string>

class Timer {
public:
    explicit Timer(int totalSec = 0);
    void start(int totalSec);
    void tick();               // decrementa di 1 s
    bool isFinished() const;
    bool isRunning() const;
    int  remaining() const;    // secondi rimasti
    std::string remainingStr() const; // H:M:S
private:
    int secondsLeft{0};  //inizializzato a 0
    bool running{false}; //inizializzato a falso
};


#endif //ELABORATOTIMER_TIMER_H
