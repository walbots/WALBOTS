#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Motor,  mtr_S1_C1_1,     motorA,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorB,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoStandard)


#include "JoystickDriver.c"

void initializeRobot()
{
	return;
}

task main()
{

	waitForStart();

	motor[motorD] = -10;
	motor[motorA] = -10;
	motor[motorB] = -10;
	motor[motorE] = -10;
	wait1Msec(1000);

	motor[motorF] = 10;
	motor[motorG] = 10;
	wait1Msec(1500);

	motor[motorF] = -10;
	motor[motorG] = -10;

}
