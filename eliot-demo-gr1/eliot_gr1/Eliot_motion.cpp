#include <Eliot_motion.h>

int motion_state = 0;
int no_cpt=0;

Eliot_motion::Eliot_motion(){
}

void Eliot_motion::init(void){
	pinMode(A5, INPUT);
    frequency = MIN_FREQUENCY;
    cpt = 0;
}

short Eliot_motion::get_data(int data[20]) {
  data[0] = motion_state;
  data[1] = cpt;
  data[2] = no_cpt;
  cpt = 0;
  no_cpt = 0;
  return 3;
}

short Eliot_motion::read(void) {
  short result = 1;
  int previous = motion_state;
  motion_state = digitalRead(A5);
  if(motion_state != previous){
	  if(motion_state == HIGH){
		  cpt++;
	  } else {
		  no_cpt++;
	  }
  }
  digitalWrite(GREEN, motion_state);
  digitalWrite(RED, motion_state);
  return result;
}

void Eliot_motion::set_frequency(unsigned long freq) {
  if (freq >= MIN_FREQUENCY) {
    frequency = freq;
  }
}

unsigned long Eliot_motion::get_frequency(void) {
  return frequency;
}
