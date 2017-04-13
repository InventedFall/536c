#pragma config(Sensor, in1,    ArmPot,         sensorPotentiometer)
#pragma config(Sensor, in2,    GyroSensor,     sensorGyro)
#pragma config(Sensor, in3,    CLAWW,          sensorPotentiometer)
#pragma config(Sensor, in4,    xAxis,          sensorAccelerometer)
#pragma config(Sensor, in5,    yAxis,          sensorAccelerometer)
#pragma config(Sensor, in6,    zAxis,          sensorAccelerometer)
#pragma config(Sensor, dgtl1,  frontRightEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  solenoid,       sensorDigitalOut)
#pragma config(Sensor, dgtl5,  solenoid2,      sensorDigitalOut)
#pragma config(Sensor, dgtl6,  frontLeftEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  solenoid3,      sensorDigitalOut)
#pragma config(Sensor, dgtl11, Touch,          sensorTouch)
#pragma config(Motor,  port1,           L1,            tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           L2,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           lift1,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           lift2,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           lift3,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           R1,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           R2,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           lift4,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           lift5,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          lift6,         tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(DatalogSeries, 0, "Right Drive motor", Motors, MotorRunState, port2, 50)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//	\\		//				 //\\				\\          //		||||		||||||||||||		|||||||||                             //
//	 \\	 //					//  \\			 \\        //     ||||		||              ||     ||                             //
//		\\//				 //||||\\				\\      //							||||||||||||    ||     ||                             //
//		//\\				// 			\\			 \\		 //				 ||			||              |||||||||                             //
//	 //	 \\			 //			   \\				\\  //         ||			||              ||      \\                            //
//	//		\\		//				  \\			 \\//          ||	 	  ||||||||||||    ||       \\                           //
//                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MAIN PROGRAM DESCRIPTIONS
// -------------------------
// This Version of Code is designed to be co-compatible with both Vex 0.5 and Vex Cortex (2.0)
// micro-controllers. All the loading is done automatically when you choose which platform you want in the menu.


// PROGRAM NOTES
// -------------
// NOTE: All bugs should be fixed in Version 1.7
// NOTE: This program referances other programs, these programs need to be referanced with in this file, and
//       all files must be in the same folder.

// PROGRAM VERSION
// ---------------
// Version: 9.0.1 ""
//		-Added new file systems. Restructured all file systems and organized code significantly.
//		 Fixed and restructured background code
//		-Added new auton funtions+lcd (Driver Debug)

// PROGRAM PLANS
//--------------
// To edit the auton selection task to display information about the auton on the selection screen
// (Still needs to be done)((Not implimented yet"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Define encoder counts per revolution depending on motor
//This is helpful when programing Auton or Programing skills
#define MOTOR_TPR_269           240.448
#define MOTOR_TPR_393R          261.333
#define MOTOR_TPR_393S          392
#define MOTOR_TPR_393T          627.2
#define MOTOR_TPR_QUAD          360.0
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BACKAROUND CODE: Main competition background code...do not modify unless you know what you are doing!!!!
//#include "Vex_Competition_Includes.c"
//  OR:
//#include "StarStruckIncludes.c"
#include "SmartMotorLib.c"
//#include "Vex_Competition_Includes.c"
#include "StarStruckIncludes.c"

// BACKAROUND CODE:Auton Functions
#include "AutonFunct.c"

// BACKAROUND CODE:Driver Debug Functions
//#include "DebugFunctions.c"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Autons
#include "Auton1.c"
#include "Auton2.c"
#include "Auton3.c"
#include "Auton4.c"
#include "Auton5.c"
#include "Auton6.c"
#include "Auton7.c"
#include "Auton8.c"
#include "Auton9.c"
#include "Auton10.c"
#include "Auton11.c"
#include "Auton12.c"
#include "Auton13.c"
#include "Auton14.c"
// Autnon Descriptions---should be up to date?
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//autonomous 1 ()//left side cube+4 stars
//autonomous 2 ()//right side cube+4 stars
//autonomous 3 ()//left side 2 stars
//autonomous 4 ()//right side 2 stars
//autonomous 5 () //block from left square
//autonomous ()//skills//         //new skills tht may actually work?
//autonomous 7 ()//1st skils?-Backup !!commented out!!-will not run
//autonomous 8 ()//left side 2 stars?-Backup !!commented out!!-will not run
// autonomous ()//right side 2 stars?-Backup !!commented out!!-will not run
//autonomous 10 ()
////10-14  currently empty, select these during inspection so the robot won't drive off the table, or when no auton is desired
//autonomous 14 ()
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pre_auton()
{
	bLCDBacklight = true;

	string str;

	//startTask(SmartMotorTask);
	//// Initialize smart motor library
	//SmartMotorsInit();

	//SmartMotorSetPowerExpanderStatusPort( in7 );

	//SmartMotorPtcMonitorEnable();
	////SmartMotorCurrentMonitorEnable();

	//SmartMotorSetControllerStatusLed( SMLIB_CORTEX_PORT_0, dgtl10 );
	////SmartMotorSetControllerStatusLed( SMLIB_CORTEX_PORT_1, dgtl11 );
	////SmartMotorSetControllerStatusLed( SMLIB_PWREXP_PORT_0, dgtl12 );
	////SmartMotorSetSlewRate( leftMotor,  10 ) ;
	////SmartMotorSetSlewRate( rightMotor,  10 ) ;
	////void SmartMotorSetSlewRate( tMotor index, int slew_rate );
	////SmartMotorSetControllerStatusLed( SMLIB_CORTEX_PORT_0, statusLED );
	//SmartMotorDebugStatus() ;

	////SmartMotorsSetEncoderGearing(leftMotor, 2) ;
	//// run background tasks
	//SmartMotorRun();

	//// one encoder for all arm motors
	////SmartMotorLinkMotors( lift2, lift2 );
	//SmartMotorLinkMotors( lift2, lift3 );
	//SmartMotorLinkMotors( lift2, lift4 );
	//SmartMotorLinkMotors( lift2, lift5 );
	//SmartMotorLinkMotors( lift2, lift6 );

	//SmartMotorLinkMotors( L1, L2 );
	//SmartMotorLinkMotors( r1, r2 );


	//SmartMotorSetRpmSensor(lift2,in1,6000 ) ;
	//			//SmartMotorSetRpmSensor(lift2,in1,6000 ) ;
	//			//SmartMotorSetRpmSensor(L1,dgtl6,360 ) ;
	//			//SmartMotorSetRpmSensor(r1,dgtl1,360 ) ;
	//SmartMotorsAddPowerExtender( port4, port7, port6) ;

	// NOTE: Task auton selection was moved to background code
	//startTask(autonomousSelection);  //starts auton selection
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
task autonomous()//defines autonoums selected
{
	if (autonomousMode == 1)
	{
		Auton1();
	}
	else if (autonomousMode == 2)
	{
		Auton2();
	}
	else if (autonomousMode == 3)
	{
		Auton3();
	}
	else if (autonomousMode == 4)
	{
		Auton4();
	}
	else if (autonomousMode == 5)
	{
		Auton5();
	}
	else if (autonomousMode == 6)
	{
		Auton6();
	}
	else if (autonomousMode == 7)
	{
		Auton7();
	}
	else if (autonomousMode == 8)
	{
		Auton8();
	}
	else if (autonomousMode == 9)
	{
		Auton9();
	}
	else if (autonomousMode == 10)
	{
		Auton10();
	}
	else if (autonomousMode == 11)
	{
		Auton11();
	}
	else if (autonomousMode == 12)
	{
		Auton12();
	}
	else if (autonomousMode == 13)
	{
		Auton13();
	}
	else if (autonomousMode == 14)
	{
		Auton14();
	}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
task usercontrol()
{
//	startTask(driverControlViewValues);
	bool curve = true;  //drive function
	bool control = false; //drive function
	bool inversed = false; //drive function
	bLCDBacklight = true;	// Turn on LCD Backlight for visiblity
	string mainBattery;// displays battery voltage on lcd
	float LeftIn;//drive function
	float RightIn;//drive function

	while(true)
	{
		if(driverControlModeCount == 4 && nLCDButtons == 2)//starts auton in driver useful during
		{																									// practice
			startTask(autonomous);
			clearTimer(T2);
			displayLCDString(0, 0, "autonomous");
			displayLCDNumber(1,0,time1[T2],4);
			while(time1[T2] < 15000)
			{
				displayLCDString(0, 0, "autonomous");
				displayLCDNumber(1,0,time1[T2]);
			}
			stopTask(autonomous);
		}


		if (nVexRCReceiveState & vrXmit2)//if 2 controler
		{
			/////////////////////////////////////////////////////////////////////////////////


			motor[lift1]= vexRT[Ch3Xmtr2];
			motor[lift2]= vexRT[Ch3Xmtr2];
			motor[lift3]= vexRT[Ch3Xmtr2];
			motor[lift4]= vexRT[Ch3Xmtr2];//...raise the arm.
			motor[lift5]= vexRT[Ch3Xmtr2];
			motor[lift6]= vexRT[Ch3Xmtr2];


			if(vexRT[Btn6UXmtr2] == 1)         // If button 6U (upper right shoulder button) is pressed:
			{
				SensorValue[solenoid3] = 1;


				// ...activate the solenoid.
			}
			else                          // If button 6U (upper right shoulder button) is  NOT pressed:
			{
				SensorValue[solenoid3] = 0;

				;// ..deactivate the solenoid.
			}





			if(vexRT[Btn6DXmtr2] == 1)         // If button 6U (upper right shoulder button) is pressed:
			{
				SensorValue[solenoid] = 1;
				SensorValue[solenoid2] = 1;

				// ...activate the solenoid.
			}
			else                          // If button 6U (upper right shoulder button) is  NOT pressed:
			{
				SensorValue[solenoid] = 0;
				SensorValue[solenoid2] = 0;
				;// ..deactivate the solenoid.
			}



			if (curve)//parabloic curve
			{
				LeftIn=(vexRT[Ch3]*vexRT[Ch3])/127.0;
				RightIn=(vexRT[Ch2]*vexRT[Ch2])/127.0;
				if(vexRT[Ch3] < 0)
				{
					LeftIn=LeftIn*-1.0;
				}
				if(vexRT[Ch2] < 0)
				{
					RightIn=RightIn*-1.0;
				}
			}
			else
			{
				LeftIn=vexRT[Ch3];//regular drive
				RightIn=vexRT[Ch2];
			}

			if(control)
			{
				LeftIn=(vexRT[Ch3]/2);//drive speed cut in half for control
				RightIn=(vexRT[Ch2]/2);
			}

			if(!inversed)//drive inversed for hanging
			{
				chassisDrive(LeftIn,RightIn);
			}
			else
			{
				chassisDrive(-RightIn, -LeftIn,);
			}
			/////////////////////////////////////////////////////////////////////////////////


			if (vexRT[Btn7U]==1)//controls drive speeds shown above
			{
				curve=true;
			}
			if (vexRT[Btn7D]==1)
			{
				curve=false;
			}

			if(vexRT[Btn8U]==1)
			{
				control = true;
			}
			if(vexRT[Btn8D]==1)
			{
				control = false;
			}

			if(vexRT[Btn7L]==1)
			{
				inversed = false;
			}
			if(vexRT[Btn7r]==1)
			{
				inversed = true;
			}
		}



		else//else 1 controler
		{
			if (curve)//parabloic curve
			{
				LeftIn=(vexRT[Ch3]*vexRT[Ch3])/127.0;
				RightIn=(vexRT[Ch2]*vexRT[Ch2])/127.0;
				if(vexRT[Ch3] < 0)
				{
					LeftIn=LeftIn*-1.0;
				}
				if(vexRT[Ch2] < 0)
				{
					RightIn=RightIn*-1.0;
				}
			}
			else
			{
				LeftIn=vexRT[Ch3];//regular drive
				RightIn=vexRT[Ch2];
			}

			if(control)
			{
				LeftIn=(vexRT[Ch3]/2);
				RightIn=(vexRT[Ch2]/2);//drive speed cut in half for control
			}

			if(!inversed)//drive inversed for hanging
			{
				chassisDrive(LeftIn,RightIn);
			}
			else
			{
				chassisDrive(-RightIn, -LeftIn,);
			}
			/////////////////////////////////////////////////////////////////////////////////

			if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
			{
				motor[lift1]= 127;
				motor[lift2]= 127;
				motor[lift3]= 127;
				motor[lift4]= 127;//...raise the arm.
				motor[lift5]= 127;
				motor[lift6]= 127;
			}
			else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
			{
				motor[lift1]= -127;
				motor[lift2]= -127;
				motor[lift3]= -127;
				motor[lift4]=- 127;
				motor[lift5]=- 127;
				motor[lift6]= -127;

			}
			else                      		//Else (neither button is pressed)...
			{
				motor[lift1]= 0;
				motor[lift2]= 0;
				motor[lift3]= 0;
				motor[lift4]= 0;
				motor[lift5]= 0;
				motor[lift6]= 0;
			}


			if(vexRT[Btn6U] == 1)         // If button 6U (upper right shoulder button) is pressed:
			{
				SensorValue[solenoid3] = 1;


				// ...activate the solenoid.
			}
			else                          // If button 6U (upper right shoulder button) is  NOT pressed:
			{
				SensorValue[solenoid3] = 0;

			// ..deactivate the solenoid.
			}



			if(vexRT[Btn6D] == 1)         // If button 6U (upper right shoulder button) is pressed:
			{
				SensorValue[solenoid] = 1;
				SensorValue[solenoid2] = 1;

				// ...activate the solenoid.
			}
			else                          // If button 6U (upper right shoulder button) is  NOT pressed:
			{
				SensorValue[solenoid] = 0;
				SensorValue[solenoid2] = 0;
				;// ..deactivate the solenoid.
			}

		if (vexRT[Btn7U]==1)//controls drive speeds shown above
			{
				curve=true;
			}
			if (vexRT[Btn7D]==1)
			{
				curve=false;
			}

			if(vexRT[Btn8U]==1)
			{
				control = true;
			}
			if(vexRT[Btn8D]==1)
			{
				control = false;
			}

			if(vexRT[Btn7L]==1)
			{
				inversed = false;
			}
			if(vexRT[Btn7r]==1)
			{
				inversed = true;
			}
			/////////////////////////////////////////////////////////////////////////////////




		}
		/////////////////////////////////
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
