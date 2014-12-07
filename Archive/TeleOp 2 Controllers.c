#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C2_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    spinservo,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_4,    armservo,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    sprocketservo,        tServoContinuousRotation)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to initialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();
  int threshold = 20;

  waitForStart();   // wait for start of tele-op phase

  while (true)
  {    getJoystickSettings(joystick);
    if(abs(joystick.joy1_y2) > threshold)   // If the right analog stick's Y-axis readings are either above or below the threshold:
    {
      motor[motorD] = joystick.joy1_y2;         // Motor D is assigned a power level equal to the right analog stick's Y-axis reading.
      motor[motorE] = joystick.joy1_y2;         // Motor E is assigned a power level equal to the right analog stick's Y-axis reading.
    }
    else                                    // Else if the readings are within the threshold:
    {
      motor[motorD] = 0;                        // Motor D is stopped with a power level of 0.
      motor[motorE] = 0;                        // Motor E is stopped with a power level of 0.
    }


    if(abs(joystick.joy1_y1) > threshold)   // If the left analog stick's Y-axis readings are either above or below the threshold:
    {
      motor[motorF] = joystick.joy1_y1;         // Motor E is assigned a power level equal to the left analog stick's Y-axis reading.
      motor[motorG] = joystick.joy1_y1;         // Motor G is assigned a power level equal to the right analog stick's Y-axis reading.
    }
    else                                    // Else if the readings are within the threshold:
    {
      motor[motorF] = 0;                        // Motor E is stopped with a power level of 0.
      motor[motorG] = 0;                        // Motor G is stopped with a power level of 0.
    }


    // BUTTONS TO CONTOL SERVO ARM
    // Control arm via shoulder buttons, 5 and 6... 5=up, 6=down

    if(joy2Btn(5))          // If Button 5 is pressed:
    {
      servo[servo1] = 180;      // Raise Servo 1 to position 180.
      servo[servo2] = 180;      // Raise Servo 2 to position 180.
      servo[servo5] = 180;      // Raise Servo 5 to position 180.
    }

    if(joy2Btn(7))          // If Button 7 is pressed:
    {
      servo[servo1] = 0;       // Lower Servo 1 to position 0.
      servo[servo2] = 0;       // Lower Servo 2 to position 0.
      servo[servo5] = 0;       // Lower Servo 5 to position 0.
    }

    if(joy2Btn(6) ==1)
    {
      motor[motorC] = -25;
    }

    if(joy2Btn(8) ==1)
    {
      motor[motorC] = 25;
    }

    if(joy2Btn(4) ==1)          // If Button 4 is pressed:
    {
      servo[armservo] = 255;
      //servo[spinservo2] = 0;    // Raise Servo 3 to position 180.
    }

    if(joy2Btn(2) ==1)          // If Button 2 is pressed:
    {
      servo[armservo] = 45;
      //servo[spinservo2] = 255;  // Lower Servo 3 to position 0.
    }

    if(joy2Btn(3) ==1)
    {
      servo[sprocketservo] = 99;
      //servo[spr] = 127;
    }

    if(joy1Btn(1) ==1)
    {
      motor[motorB] = -100;
    }
    else
    {
      motor[motorB] = 0;
    }

    if(joy2Btn(1) ==1)
    {
      motor[motorA] = 100;
    }
    else
    {
      motor[motorA] = 0;
    }



	  ///////////////////////////////////////////////////////////
	  ///////////////////////////////////////////////////////////
	  ////                                                   ////
	  ////      Add your robot specific tele-op code here.   ////
	  ////                                                   ////
	  ///////////////////////////////////////////////////////////
	  ///////////////////////////////////////////////////////////

    // Insert code to have servos and motors respond to joystick and button values.

    // Look in the ROBOTC samples folder for programs that may be similar to what you want to perform.
    // You may be able to find "snippets" of code that are similar to the functions that you want to
    // perform.
  }
}
