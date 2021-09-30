#include"main.h"
void homeShoulder(){
  while(digitalRead(LIMIT_SWITCH) != LOW){
    shoulderSet(40);
  }
}
