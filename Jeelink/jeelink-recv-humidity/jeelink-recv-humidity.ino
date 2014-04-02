#include <jeelib.h>

void setup() {
  Serial.begin(57600);
  rf12_initialize(18, RF12_915MHZ, 68);
  
  Serial.print("Receiving data...");
}

void loop() {
  if (rf12_recvDone() && rf12_crc == 0) {
    int* buf = (int*) rf12_data;
    for (int i=0; i<3; i++) {
      Serial.print(buf[i]);
      Serial.print(" ");
    }
    Serial.print("\n");
  }
}
