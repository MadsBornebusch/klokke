
#include <avr/pgmspace.h>
#define FLASH_ARRAY_SIZE 10*24*2
#define HS 60*60
#define MS 60
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1ULL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1ULL << (bit)))
#define bitSet64(value, bit) ((value) |= (1ULL << (bit)))
#define bitClear64(value, bit) ((value) &= ~(1ULL << (bit)))
//#define bitWrite64(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
const uint32_t EOW = 43200;
const uint32_t DONETIME = 28800;
const uint32_t EOD = 86400;


const uint8_t daysInMonth [] PROGMEM = { 31,28,31,30,31,30,31,31,30,31,30,31 };

const uint8_t klokkeslett[FLASH_ARRAY_SIZE] PROGMEM = {
// 0
6,15,  2,45,  2,45,  5,45,
6,00,  6,15,  5,45,  6,00,
6,00,  6,00,  6,00,  6,00,
6,00,  6,00,  6,00,  6,00,
6,00,  3,00,  9,00,  6,00,
3,00,  2,45,  2,45,  9,00,

//1
6,15,  2,45,  5,45,  7,38,
3,00,  5,45,  6,00,  7,38,
7,38,  6,00,  6,00,  7,38,
7,38,  6,00,  6,00,  7,38,
6,15,  9,00,  3,00,  5,45,
3,00,  2,45,  2,45,  9,00,
//2
6,15,  2,45,  2,45,  5,45,
3,00,  2,45,  5,45,  6,00,
6,15,  2,45,  9,00,  6,00,
6,00,  6,15,  2,45,  9,00,
6,00,  3,00,  2,45,  5,45,
3,00,  2,45,  2,45,  9,00,
//3
6,15,  2,45,  2,45,  5,45,
3,00,  2,45,  5,45,  6,00,
7,38,  6,15,  9,00,  6,00,
7,38,  3,00,  5,45,  6,00,
6,15,  2,45,  9,00,  6,00,
3,00,  2,45,  2,45,  9,00,
//4
6,15,  5,45,  6,15,  5,45,
6,00,  6,00,  6,00,  6,00,
6,00,  3,00,  9,00,  6,00,
3,00,  2,45,  5,45,  6,00,
7,38,  7,38,  6,00,  6,00,
7,38,  7,38,  3,00,  9,00,
//5
6,15,  2,45,  2,45,  5,45,
6,00,  6,15,  2,45,  9,00,
6,00,  3,00,  2,45,  5,45,
3,00,  2,45,  5,45,  6,00,
6,15,  2,45,  9,00,  6,00,
3,00,  2,45,  2,45,  9,00,
//6
6,15,  2,45,  2,45,  5,45,
6,00,  6,15,  2,45,  9,00,
6,00,  3,00,  2,45,  5,45,
6,00,  6,15,  5,45,  6,00,
6,00,  3,00,  9,00,  6,00,
3,00,  2,45,  2,45,  9,00,
//7
6,15,  2,45,  2,45,  5,45,
3,00,  2,45,  5,45,  6,00,
7,38,  7,38,  6,00,  6,00,
7,38,  7,38,  6,00,  6,00,
7,38,  7,38,  6,00,  6,00,
7,38,  7,38,  3,00,  9,00,

//8
6,15,  2,45,  2,45,  5,45,
6,00,  6,15,  5,45,  6,00,
6,00,  3,00,  9,00,  6,00,
6,00,  6,15,  5,45,  6,00,
6,00,  3,00,  9,00,  6,00,
3,00,  2,45,  2,45,  9,00,
//9
6,15,  2,45,  2,45,  5,45,
6,00,  6,15,  5,45,  6,00,
6,00,  3,00,  9,00,  6,00,
3,00,  2,45,  5,45,  6,00,
6,15,  2,45,  9,00,  6,00,
3,00,  2,45,  2,45,  9,00
};



int16_t getDest(uint8_t watch) {
  uint8_t hour = pgm_read_byte_near(klokkeslett + (2*watch));
  uint8_t minute = pgm_read_byte_near(klokkeslett + (2*watch) + 1);
  int16_t dest_min = 60*((int16_t) hour) + ((int16_t) minute);
  return dest_min;
  };


