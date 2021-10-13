;/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include"homeShoulder.h"
#include"homeElbow.h"

 void operatorControl() {
   int power, turn;
   Encoder encoder;
   encoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, true);
   int counts = encoderGet(encoder);
   Encoder encoder2;
   encoder2 = encoderInit(QUAD_TOP_PORT2, QUAD_BOTTOM_PORT2, true);
   int counts2 = encoderGet(encoder2);


   while (1) {

      power = joystickGetAnalog(1, 1); // vertical axis on left joystick
      turn = joystickGetAnalog(1, 2); // horizontal axis on left joystick
  //    counts = encoderGet(encoder);
    //  counts2 = encoderGet(encoder2);
     chassisSet(0.5*(power + turn), 0.5*(power - turn));


     // add the following line:}
     clawSet(joystickGetAnalog(1, 4));
     openSet(joystickGetAnalog(1, 3));
     if (digitalRead(LIMIT_SWITCH) == LOW){
       printf("low\n");
       delay(200);

     }

     if(joystickGetDigital(1, 6, JOY_UP)) {
     shoulderSet(127); // pressing up, so lift should go up
   }
   else if(joystickGetDigital(1, 6, JOY_DOWN)) {
     shoulderSet(-127); // pressing down, so lift should go down
   }
   else {
     shoulderSet(0); // no buttons are pressed, stop the lift
   }



   if(joystickGetDigital(1, 5, JOY_UP)) {
     elbowSet(127); // pressing up, so lift should go up
   }
   else if(joystickGetDigital(1, 5, JOY_DOWN)) {
     elbowSet(-127); // pressing down, so lift should go down
   }
   else {
     elbowSet(0); // no buttons are pressed, stop the lift
   }

   if(joystickGetDigital(1, 7, JOY_UP)){
     homeShoulder();

     homeElbow();

     encoderReset(encoder);
     encoderReset(encoder2);
     while(counts<65){
       shoulderSet(-40);
       counts = encoderGet(encoder);
       delay(20);
      printf("moving to home position shoulder %d \n", counts);
     }
     shoulderSet(0);
     encoderReset(encoder2);
     while(counts2<120 ){
       elbowSet(40);
       counts2 = encoderGet(encoder2);
       delay(20);
       printf("moving to home position elbow %d \n", counts2);
     }
     elbowSet(0);
     encoderReset(encoder);
     encoderReset(encoder2);

     printf(" shoulder homed %d \n", counts);
     printf("elbow homed %d \n", counts2);


   }
   delay(20);
   printf("shoulder current %d \n", counts);
   printf("elbow current %d \n", counts2);


    printf("high\n");
  //  printf("the count value shoulder %d \n", counts);
  //  printf("the count value elbow %d \n", counts2);
    delay(200);
  }
 }
