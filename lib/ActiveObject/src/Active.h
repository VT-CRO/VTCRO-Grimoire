#include "arduino_freertos.h"
#include "queue.h"  

typedef struct
{
    uint8_t sig;
    uint8_t param;
} Event_t;

class Active {
    private:
        TaskHandle_t s_thread;
        QueueHandle_t s_eventQueue;

    public:
        Active();
        ~Active();

        void start(uint8_t prio, uint8_t queueLen, uint8_t opt);

        virtual void dispatch() = 0;
        void post(Event_t e);
        void postFromIST(Event_t e);
        
};