/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

 #include "main.h"
 void myFunction(){
     // ... Do work
     // Get encoder reading in degrees
     int counts = encoderGet(encoder);

     // ... Do other work
     // Reset encoder to zero
     encoderReset(encoder);
 }


 void operatorControl() {
   int power, turn;
   int pot = 0;
   while (1) {
      power = joystickGetAnalog(1, 1); // vertical axis on left joystick
      turn = joystickGetAnalog(1, 2); // horizontal axis on left joystick

     chassisSet(-0.5*(power + turn), -0.5*(power - turn));

     // add the following line:
     clawSet(joystickGetAnalog(1, 4));
     openSet(joystickGetAnalog(1, 3));
     if (digitalRead(LIMIT_SWITCH) == LOW){
       while(digitalRead(LIMIT_SWITCH) == LOW){
       printf("low\n");
       delay(200);
     }
     }
     else{
     if(joystickGetDigital(1, 6, JOY_UP)) {
     shoulderSet(127); // pressing up, so lift should go up
   }
   else if(joystickGetDigital(1, 6, JOY_DOWN)) {
     shoulderSet(-127); // pressing down, so lift should go down
   }
   else {
     shoulderSet(0); // no buttons are pressed, stop the lift
   }
   printf("high");
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
     delay(20);



  /// pot = analogRead(4);
  //  printf("the pot value %d \n", pot);
  //  delay(200);
  }
 }
