#ifndef Eliot_motion_h
#define Eliot_motion_h

#include <Eliot_sensor.h>

#define MIN_FREQUENCY 100

class Eliot_motion: public Eliot_sensor
{
public:
  Eliot_motion(void);
  void init(void);
  short get_data(int data[10]);
  short read(void);
  void set_frequency(unsigned long freq);
  unsigned long get_frequency(void);
};

#endif
