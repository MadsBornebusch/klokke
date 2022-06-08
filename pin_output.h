#define LBATT_PIN 19
#define N_CLOCKS 48

// Seen from the back
const uint8_t pins[N_CLOCKS] = {
2,  3,  4,  5,  6,  7,  8,  9,
10, 11, 12, 13, 14, 15, 16, 17, 
22, 23, 24, 25, 26, 27, 28, 29,
30, 31, 32, 33, 34, 35, 36, 37,
38, 39, 40, 41, 42, 43, 44, 45,
46, 47, 48, 49, 50, 51, 52, 53
};


// // Seen from the front
// const uint8_t pins[N_CLOCKS] = {
// 9,  8,  7,  6,  5,  4,  3,  2,
// 17, 16, 15, 14, 13, 12, 11, 10,
// 29, 28, 27, 26, 25, 24, 23, 22, 
// 37, 36, 35, 34, 33, 32, 31, 30,
// 45, 44, 43, 42, 41, 40, 39, 38,
// 53, 52, 51, 50, 49, 48, 47, 46
// };


void turnOffPin(uint8_t pin_number){
  pinMode(pin_number, INPUT);
}

void turnOnPin(uint8_t pin_number){
  pinMode(pin_number, OUTPUT);
  digitalWrite(pin_number, LOW);
}

void setupOutput(void){
  for(uint8_t i = 0; i < N_CLOCKS; i++) {
    turnOffPin(pins[i]);
  }
}

void shiftOut(byte myDataOut, uint8_t latchon, uint8_t row) {
  for(uint8_t i = 0; i < 8; i++) {
    uint8_t pin_number = pins[(N_CLOCKS -1) - (row * 8 + i)];
    if(bitRead(myDataOut, i) == 1) {
      turnOnPin(pin_number);
      Serial.print("Turning on pin ");
      Serial.println(pin_number);
    } else {
      turnOffPin(pin_number);
    }
  }
}
