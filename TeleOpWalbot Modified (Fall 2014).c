#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorB,          nxtmotorB,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          nxtmotorC,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorC,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorA,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorB,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)b
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
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
  int threshold = 30;

  waitForStart();   // wait for start of tele-op phase

while (true)
		{    getJoystickSettings(joystick);
    if(abs(joystick.joy1_y2) > threshold)   // If the right analog stick's Y-axis readings are either above or below the threshold:
    {
      motor[motorB] = joystick.joy1_y2;         // Motor D is adssigned a power level equal to the right analog stick's Y-axis reading.
      motor[motorD] = joystick.joy1_y2;         // Motor E is assigned a power level equal to the right analog stick's Y-axis reading.
    }
    else                                    // Else if the readings are within the threshold:
    {
      motor[motorB] = 0;                        // Motor D is stopped with a power level of 0.
      motor[motorD] = 0;                        // Motor E is stopped with a power level of 0.
    }

    if(abs(joystick.joy1_y1) > threshold)   // If the left analog stick's Y-axis readings are either above or below the threshold:
    {
      motor[motorA] = joystick.joy1_y1;         // Motor E is assigned a power level equal to the left analog stick's Y-axis reading.
      motor[motorC] = joystick.joy1_y1;         // Motor G is assigned a power level equal to the right analog stick's Y-axis reading.
    }
    else                                    // Else if the readings are within the threshold:
    {
      motor[motorA] = 0;                        // Motor E is stopped with a power level of 0.
      motor[motorC] = 0;                        // Motor G is stopped with a power level of 0.
    }

			if(abs(joystick.joy2_y1) > threshold)		//left joystick of 2nd controller activates rack and pinion = to value of y-axis.
			{																				//need button to activate servo of second rack and pinion
				motor[motorF] = joystick.joy2_y1;
			}
			else
			{
				motor[motorF] = 0;
			}

			if(abs(joystick.joy2_y2) > threshold)		//left joystick of 2nd controller activates rack and pinion = to value of y-axis.
			{																				//need button to activate servo of second rack and pinion
				motor[motorG] = joystick.joy2_y2;
			}
			else
			{
				motor[motorG] = 0;
			}

	if(joy2Btn(5))
	{
		motor[nxtmotorB] = 100;
		motor[nxtmotorC] = 100;
	}

	if(joy2Btn(6))
	{
		motor[nxtmotorB] = -50;
		motor[nxtmotorC] = -50;
	}

		if(joy2Btn(7))
	{
		motor[nxtmotorB] = 0;
		motor[nxtmotorC] = 0;
	}

	if(joy2Btn(2))
	{
		servo[servo1] = 190 ;
	}

	if(joy2Btn(4))
	{
		servo[servo1] = 10;
	}

}
}
// Motor D is stopped with a power level of 0.