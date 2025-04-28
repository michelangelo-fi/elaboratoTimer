//
// Created by michelangelo on 28/04/25.
//

#include "Timer.h"
#include <sstream>
#include <iomanip>

Timer::Timer(int totalSec){ start(totalSec); }

void Timer::start(int totalSec){
    secondsLeft = totalSec > 0 ? totalSec : 0;
    running = secondsLeft > 0;  //se 0>0 allora running= false
}

void Timer::tick(){
    if(!running) return; //se il timer non è avviato allora non fa alcun decremento
    if(--secondsLeft <= 0){ //non misura tempo, fa solo il conto dei secondi che mancano
        secondsLeft = 0; //forzo a 0 per evitare numeri negativi
        running = false;
    }
}

bool Timer::isFinished() const { return !running; }
bool Timer::isRunning()  const { return running; }
int  Timer::remaining()  const { return secondsLeft; }

std::string Timer::remainingStr() const {

    int h = secondsLeft/3600, m=(secondsLeft%3600)/60, s=secondsLeft%60;
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2)
        << m << ":" << std::setw(2) << s;
    return oss.str();
}

