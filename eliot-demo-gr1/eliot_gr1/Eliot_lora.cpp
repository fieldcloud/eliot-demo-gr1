#include <Eliot_lora.h>

Eliot_lora::Eliot_lora(){
}

short Eliot_lora::init(void){
    interval = MIN_PERIOD;
  digitalWrite(RF, HIGH);
  Serial.begin(19200);
  delay(10000);
  return 1;
}

short Eliot_lora::send(int experimentation, int device_code, int batt, int sensor_code, short lenght, int payload[10]) {
  if (lenght > 10) {
    return 0;
  } else {
    digitalWrite(BLUE, HIGH);
    Serial.print("+++");
    delay(1000);
    Serial.print(F("AT$SF="));
    char buff[16];
    sprintf(buff, "%.4X%.4X%.4X%.4X", experimentation, device_code, batt, sensor_code);
    Serial.print(buff);
    char buff2[4];
    for (int i = 0; i < lenght; i++) {
      sprintf(buff2, "%.4X", payload[i]);
      Serial.print(buff2);
    }
    Serial.println();
    delay(5000);
    Serial.println("ATQ");
    digitalWrite(BLUE, LOW);
    return 1;
 }
}

void Eliot_lora::set_interval(unsigned long period) {
  if (period >= MIN_PERIOD) {
    interval = period;
  }
}

unsigned long Eliot_lora::get_interval(void) {
  return interval;
}
