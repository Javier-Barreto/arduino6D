#include "DataLogger.h"

void setup() {
  // put your setup code here, to run once:
  MSD.MicroSD_init();
  RRTC.rtc_init();
}

void loop ( ) {
  
  
  delay(5000);
  MSD.JSON();
  // put your main code here, to run repeatedly:

}
