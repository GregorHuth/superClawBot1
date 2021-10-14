#include"homeShoulder.h"
#include"homeElbow.h"
void end(){
  if(joystickGetDigital(1, 7, JOY_DOWN)){
    homeShoulder();
    homeElbow();
 }
}
