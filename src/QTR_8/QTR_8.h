//
typedef struct
{
  uint16_t pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8;
  uint16_t* data;
} QTR_t;

QTR_t QTR_init(uint16_t pin1, uint16_t pin2, uint16_t pin3, uint16_t pin4, uint16_t pin5, uint16_t pin6, uint16_t pin7, uint16_t pin8, uint16_t data[]);

int changeBit (int initialVal);