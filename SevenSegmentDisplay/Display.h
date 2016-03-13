#define DIGIT_0 0b00111111
#define DIGIT_1 0b00000110
#define DIGIT_2 0b01011011
#define DIGIT_3 0b01001111
#define DIGIT_4 0b01100110
#define DIGIT_5 0b01101101
#define DIGIT_6 0b01111101
#define DIGIT_7 0b00000111
#define DIGIT_8 0b01111111
#define DIGIT_9 0b01101111

class Display{
  //Data register where display is plugged
  uint8_t * port_register;
  //Direction register
  uint8_t * direction_register;

  public:
    Display(uint8_t *, uint8_t *);
    void write_digit(uint8_t digit);

  private:
  uint8_t display_values[10] = {DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4, DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9};
};

