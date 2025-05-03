
#include "Timer.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <stdexcept>


Timer::Timer() { start(0); }
//errore è inutile passare totalsec sia al metodo start che a quello del costruttore
Timer::~Timer() { stop(); }

void Timer::start(int totalSec) {

    stop();
    if (totalSec < 0) //errore: meglio mettere un'eccezione
        throw std::invalid_argument("Timer duration must be positive");
    secondsLeft = totalSec;
    running = true;

    worker = std::thread(&Timer::workerLoop, this);
}

void Timer::stop() {
    running = false;
    if (worker.joinable()) worker.join();
}

void Timer::tick() {
    if (!running) return; //se il timer non è avviato allora non fa alcun decremento
    if (--secondsLeft <= 0) { //non misura tempo, fa solo il conto dei secondi che mancano
        secondsLeft = 0; //forzo a 0 per evitare numeri negativi
        running = false;
        if (finishCb)
            finishCb();
    } else {
        if (tickCb)
            tickCb(secondsLeft);
    }
}

bool Timer::isFinished() const { return !running; }

bool Timer::isRunning() const { return running; }

int Timer::remaining() const { return secondsLeft; }

void Timer::workerLoop() {
    while (running && secondsLeft >= 0) {
        if (tickCb) tickCb(secondsLeft);
        std::this_thread::sleep_for(std::chrono::seconds(1));  //uso chrono solo qua
        --secondsLeft;
    }

    running = false;
    if (finishCb) finishCb();
}

void Timer::onTick(TickCB cb) { tickCb = std::move(cb); }

void Timer::onFinish(FinishCB cb) { finishCb = std::move(cb); }


std::string Timer::remainingStr() const {
    int h = secondsLeft / 3600, m = (secondsLeft % 3600) / 60, s = secondsLeft % 60;
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2)
        << m << ":" << std::setw(2) << s;
    return oss.str();
}

