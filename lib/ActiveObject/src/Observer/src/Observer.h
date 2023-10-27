#include "arduino_freertos.h"

template <typename T> class Observer;
template <typename T> class Subject;

template <typename T>
class Subject {
    private:
        Observer observers[10];
        T state;

    public:
        void set_state(uint16_t s);
        void attachObserver(Observer obs);
        void notifyObservers();

    friend Observer;
};

template <typename T>
class Observer {
    private:
        Subject sub;
        T state;

    public:
        void update();
};