//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                       VEX Competition Control Include File
//
// This file provides control over a VEX Competition Match. It should be included in the user's
// program with the following line located near the start of the user's program
//        #include "VEX_Competition_Includes_.c"
// The above statement will cause this program to be included in the user's program. There's no
// need to modify this program. (Only if you know what you are doing :0)
//
// The program displays status information on the new VEX LCD about the competition state. You don't
// need the LCD, the program will work fine whether or not the LCD is actually provisioned.
// * Note to select auton- lcd is necessary
//
// The status information is still useful without the LCD. The  debugger has a "remote screen"
// that contains a copy of the status information on the LCD. YOu can use this to get a view of the
// status of your program. The remote screen is shown with the menu command
//   "Robot -> Debugger Windows -> VEX Remote Screen"
//
// The LCD is 2 lines x 16 characters.
//
//        State          Description
//
//    ----------------
//   Disabled            The robot is idle. This occurs before both the autonomous and user
//                       control states. This starts the task Auton Selction and after initializes display driverControlViewValues.
//    ----------------   This allows to reselect and reset encoders and gyro sensors and calibration of certain sensors...
//                       This is particualry useful if the robot is turned on and is in the wrong position and needs to be reset.
//                       This allows for a reset without a restart on the cortex.
//
//    ----------------
//    Autonomous         The robot is running autonomous code that was selcected during the disabled mode... Currently there are 14
//                       different autonomus modes
//
//    ----------------
//
//    ----------------
//    User Control       The robot is running user control code. Live debug can be seen through display driverControlViewValues...
//                       This can be toggled through the use of the LCD buttons or Buttons 6U and 6D... This allows to reselect
//                       and reset encoders and gyro sensors and calibration of certain sensors...
//                       This is particualry useful if the robot is turned on and is in the wrong position and needs to be reset.
//                       This allows for a reset without a restart on the cortex.
//
//    ----------------
//////////////////////////////////////////////////////////////////////////////////////////////////////

int autonomousMode =15; // integear that is changed based on auton selected =has to start greater than the max
// number of auton modes (currently 14) so + 1 = 15.....This way it does not select a
// auton 1-14 as a default -- if defult is desired the integer needs to be set to a
// negative case of that number..
void allMotorsOff();// stops all motors (Disabled)
void allTasksStop();// stops all tasks (Disabled)
void pre_auton(); // defines pre auton function --> initalizes auton selection
task autonomous(); // starts selected auton
task usercontrol(); //starts driver
int DriverDebugMax =14;

int nTimeXX = 0;//clock integer --> starts a zero
bool bStopTasksBetweenModes = true; // stops tasks in between mode True=Yes
int driverControlModeCount = 1;// Starts with default LCD case (Battery voltage)
bool curve = true;
bool inversed = false;
bool control = false;
string str;
//static void displayStatusAndTime(); // can display clock in disabled...not necasary

void clearLCD () //clear lcd text function
{
	clearLCDLine(0);
	clearLCDLine(1);
}


void displayBatteryValues ()//displays current battery voltage  (Function)
{
	string mainBatteryVoltage, backupBatteryVoltage;
	displayLCDString(0,0,"Main:");
	displayLCDString(1,0,"BackUp:");
	sprintf(mainBatteryVoltage,"%1.2f%c",nImmediateBatteryLevel/1000.0,'V');
	sprintf(backupBatteryVoltage,"%1.2f%c",BackupBatteryLevel/1000.0,'V');
	displayLCDString(0,8,mainBatteryVoltage);
	displayLCDString(1,8,backupBatteryVoltage);
}

void displayDriveControls()
{

	displayLCDPos(0,0);
	displayNextLCDString("Para Ctrl Invert");
	displayLCDPos(1,0);
	if(curve)
	{
		displayNextLCDString("on   ");
	}
	else
	{
		displayNextLCDString("off  ");
	}
	if(control)
	{
		displayNextLCDString("on   ");
	}
	else
	{
		displayNextLCDString("off  ");
	}
	if(inversed)
	{
		displayNextLCDString("on    ");
	}
	else
	{
		displayNextLCDString("off   ");
	}
}


void displayFrontEncoderValues ()// displays encoder values- can rest to zero if Middle LCD button is pressed
// and waits for a relase (Function)
{
	displayLCDCenteredString(0,"Left - Right");
	displayLCDNumber(1,1,SensorValue[frontRightEncoder],5);
	displayLCDNumber(1,9,SensorValue[frontLeftEncoder],5);
	if (nLCDButtons == 2)
	{
	SensorValue[frontRightEncoder] = 0;
	SensorValue[frontLeftEncoder]  = 0;
	}
}

void gyroValue () //shows gyro value--can zero it again br re-initilizing it (Function)
{
	displayLCDCenteredString(0,"Gyro Value");
	displayLCDNumber(1,5,SensorValue[GyroSensor],5);
	if (nLCDButtons == 2)
	{
		SensorType[GyroSensor]=sensorNone;
		wait1Msec(1200);
		SensorType[GyroSensor]=sensorGyro;
		wait1Msec(2000);
	}
}


void startAuton ()//starts auton in Driver.. useful to test auton with out competiton switch...(Function)
{
	if(nLCDButtons == 2)
	{
		clearTimer(T3);
	}
	if(time1[T3] > 15000)
	{
		displayLCDCenteredString(0,"Press to");
		displayLCDCenteredString(1,"Start Autonomous");
	}
}
void swapAuton ()//can reselect aunton if wrong one is selected(Function)
{
	displayLCDCenteredString(0,"Autonomous");
	displayLCDCenteredString(1,"Swap");
	displayLCDNumber(0,14,autonomousMode,2);
	if (nLCDButtons == 2)
	{
		autonomousMode++;
		while(nLCDButtons == 2){wait1Msec(10);}
	}
	if (autonomousMode > 14)
	{
		autonomousMode = 1;
	}
}


void displayDigitalInputs ()//displays button inputs  (Function)
{
	displayLCDCenteredString(0,"Digital Inputs");
	displayLCDNumber(1,3,SensorValue[Touch],1);

}

void nothingOnScreen ()//displays empty  (Function)
{
	displayLCDCenteredString(0,"Currently");
	displayLCDCenteredString(1,"Empty :(");
}


task driverControlViewValues ()//task to show driver debug... needs to be task to run in backround
// started in Driver see StarStruck.c (Task)
{
	clearLCD ();
	while (true)
	{
		if (vexRT[Btn7D]==1)
		{
			curve=true;
		}
		if (vexRT[Btn7L]==1)
		{
			curve=false;
		}
		if(vexRT[Btn8R]==1)
		{
			control = true;
		}
		if(vexRT[Btn8D]==1)
		{
			control = false;
		}
		if(vexRT[Btn8U]==1)
		{
			inversed = false;
		}
		if(vexRT[Btn7U]==1)
		{
			inversed = true;
		}

		if (nLCDButtons == 4)
		{
			driverControlModeCount++;//if left button or button 6 U is pressed subtract 1 from driverControlModeCount integer (defined above)
			clearLCD ();
			while(nLCDButtons == 4)
			{
				wait1Msec(10); //wait for release
			}
			while(vexRT[Btn6U] == 1) //wait for release
			{
				wait1Msec(10);
			}
		}
		if (nLCDButtons == 1)
		{
			driverControlModeCount--; //if left button or button 6 U is pressed add 1 from driverControlModeCount integer (defined above)
			clearLCD ();
			while(nLCDButtons == 1)
			{
				wait1Msec(10);
			} //wait for release
			while(vexRT[Btn6D] == 1)
			{
				wait1Msec(10); //wait for release
			}
		}
		if (driverControlModeCount < 1)//if it goes under one display next (next is 12)
		{
			driverControlModeCount = DriverDebugMax;
		}
		else if (driverControlModeCount > DriverDebugMax)//if it goes over 12display next (next is 1)
		{
			driverControlModeCount = 1;
		}

		switch (driverControlModeCount) // integer above defines which case is selected and displays it
		{
		case 1:
			displayDriveControls();
			break;
		case 2:
			displayBatteryValues();
			break;
		case 3:
			swapAuton();
			break;
		case 4:
			startAuton ();
			break;
		case 5:
			displayFrontEncoderValues();//displays drive encoders- can be zeroed by pressing center button
			break;
		case 6:
			gyroValue();
			break;
		case 7:
			displayLCDCenteredString(0,"Arm Pot");
	displayLCDNumber(1,1,SensorValue[ArmPot],5);
			break;
		case 8:
displayDigitalInputs ();
			break;
		case 9:
			displayLCDCenteredString(0,"CLAWW");
	displayLCDNumber(1,1,SensorValue[CLAWW],5);
			break;
		case 10:
nothingOnScreen();

			break;
		case 11:

		nothingOnScreen();

		case 12:
nothingOnScreen();
			break;


		}
		wait1Msec(10);
	}
}



task autonomousSelection ()//autonomous Selection...needs to be task to run in backround  (Task)
{
	bLCDBacklight = true;									// Turn on LCD Backlight
	string mainBattery, backupBattery;//prepare lcd to read battery

	while (nLCDButtons != 2)
	{
		displayLCDCenteredString(0,"<Autonomous>");
		displayLCDNumber(0,14,autonomousMode,2);  //display autonomus for selecting
		displayLCDString(1, 0, "Primary: ");   //reads battery and displays it
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);
		if (nLCDButtons == 1)//if left button is pressed
		{
			autonomousMode--;//if left button is pressed subtract 1 from autonomousSelection integer (defined above)
			while(nLCDButtons == 1){wait1Msec(10);}//wait for release
		}
		if (nLCDButtons == 4)// add  autonomousSelection variable by 1
		{
			autonomousMode++; //if left button is pressed add 1 from autonomousSelection integer (defined above)
			while(nLCDButtons == 4){wait1Msec(10);}//wait for release
		}
		if (autonomousMode < 1)//going from autonomous 1-->14...//if it goes under one display next (next is 14)
		{
			autonomousMode = 14;
		}
		else if (autonomousMode > 14)//going from autonomous 12-->1....//if it goes over one display next (next is 1)
		{
			autonomousMode = 1;
		}
		wait1Msec(10);
	}
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDCenteredString(0, "Autonomous");
	displayLCDCenteredString(1, "Selected"); //shows auton is selected and starts task driverControlViewValues
	startTask(driverControlViewValues);
}





task main() //backaround code --controls disabled, auton, and driver !!do not modify unlesss you know what you are doing!!
{
	// Master CPU will not let competition start until powered on for at least 2-seconds
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDPos(0, 0);
	displayLCDCenteredString(0, "Booting-RywnCode");
	displayLCDCenteredString(1, "Version 3.2.2");
	wait1Msec(2000);


	pre_auton();//starts pre auton--auton selection

	//wait1Msec(500);


	while (true)
	{

		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDPos(0, 0);

		while (bIfiRobotDisabled)
		{

			stopTask(usercontrol); // stops user control in disabled
			stopTask(autonomous); // stops auton in disabled
			stopTask(autonomousSelection);//resets menu system
			startTask(autonomousSelection);

			displayLCDPos(0, 0);
		//	displayNextLCDString("Disabled"); //displays disabled
			nTimeXX = 0; // time is set to 1
			while (true)
			{
				//	displayStatusAndTime();
				if (!bIfiRobotDisabled)
					break;
				wait1Msec(25);

				//		displayStatusAndTime();
				if (!bIfiRobotDisabled)
					break;
				wait1Msec(25);

				//		displayStatusAndTime();
				if (!bIfiRobotDisabled)
					break;
				wait1Msec(25);

				//	displayStatusAndTime();
				if (!bIfiRobotDisabled)
					break;
				wait1Msec(25);
				++nTimeXX;
			}
		}

		nTimeXX = 0;
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDPos(0, 0);
		if (bIfiAutonomousMode)
		{
			//		playSoundFile( "testtone.wav" );


													//	displayNextLCDString("Autonomous");
											#if (bPlayMusicDuringMatch) // if jumper in port 9 and bPlayMusicDuringMatch=true play music!
														//if (SensorValue[Playmusic]==0)
														//{
														//	//			playSoundFile("BeginMusicalSeq.wav");
														//	//playSoundFile("NyanIntro.wav"); //plays Nyan cat
														//	//playSoundFile("Nyan1.wav");
														//	//playSoundFile("Nyan1.wav");
														//	//playSoundFile("Nyan2.wav");
														//	//playSoundFile("Nyan2.wav");
														//	//playSoundFile("Nyan1.wav");
														//	//playSoundFile("Nyan1.wav");
														//	//playSoundFile("Nyan2.wav");
														//	//playSoundFile("Nyan2.wav");
														//	//playSoundFile("Nyan1.wav");

														//	//playSoundFile("Nyan1.wav");
														//	//playSoundFile("Nyan2.wav");

														//	//playSoundFile("NyanEnding.wav");

														//}
											#endif

			stopTask(autonomousSelection); //Stops Task(autonomousSelection);
			if(autonomousMode==15) // if auton selection =15 default start auton selection
			{
				startTask(autonomousSelection);//start auton selection
			}
			startTask(autonomous);//start auton
	stopTask(driverControlViewValues);
			// Waiting for autonomous phase to end
			while (bIfiAutonomousMode && !bIfiRobotDisabled)
			{
				if (!bVEXNETActive)
				{
					if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
						allMotorsOff();
				}
				wait1Msec(25);               // Waiting for autonomous phase to end
			}
			allMotorsOff();//stops everything
			if(bStopTasksBetweenModes)
			{
				allTasksStop();//stops everything
			}
		}

		else
		{
		//	displayNextLCDString("User Control");
			startTask(usercontrol);//starts user control
				startTask(driverControlViewValues);
			stopTask(autonomousSelection); //stops auton
			// Here we repeat loop waiting for user control to end and (optionally) start
			// of a new competition run
			while (!bIfiAutonomousMode && !bIfiRobotDisabled)
			{
				if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
					allMotorsOff();
				wait1Msec(25);
			}
			allMotorsOff();
			if(bStopTasksBetweenModes)
			{
				allTasksStop();
			}
		}
	}
}


void allMotorsOff()//function to turn off motors
{
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
#if defined(VEX2)
	motor[port9] = 0;
	motor[port10] = 0;
#endif
}

void allTasksStop()//function to turn off tasks
{
	stopTask(1);
	stopTask(2);
	stopTask(3);
	stopTask(4);
#if defined(VEX2)
	stopTask(5);
	stopTask(6);
	stopTask(7);
	stopTask(8);
	stopTask(9);
	stopTask(10);
	stopTask(11);
	stopTask(12);
	stopTask(13);
	stopTask(14);
	stopTask(15);
	stopTask(16);
	stopTask(17);
	stopTask(18);
	stopTask(19);
#endif
}

//static void displayStatusAndTime()
//{
//  displayLCDPos(1, 0);
//	if (bIfiRobotDisabled)
//	  displayNextLCDString("Disable ");
//	else
//	{
//	  if (bIfiAutonomousMode)
//	    displayNextLCDString("Auton  ");
//	  else
//	    displayNextLCDString("Driver ");
//	}
//	displayNextLCDNumber(nTimeXX / 600, 2);
//	displayNextLCDChar(':');
//	displayNextLCDNumber((nTimeXX / 10) % 60, -2);
//	displayNextLCDChar('.');
//	displayNextLCDNumber(nTimeXX % 10, 1);
//}


//static void UserControlCodePlaceholderForTesting()
//{
//  // Following code is simply for initial debuggging.
//  //
//  // It can be safely removed in a real program	and removing it will slightly improve the
//  // real-time performance of your robot.
//	//
//  displayStatusAndTime();
//	wait1Msec(100);
//	++nTimeXX;
//}

//static void AutonomousCodePlaceholderForTesting()
//{
//	// This is where you insert your autonomous code. Because we don't have any, we'll
//	// simply display a running count of the time on the VEX LCD.

//	while (true)
//	{
//	  displayStatusAndTime();
//		wait1Msec(100);
//		++nTimeXX;
//	}
//}
