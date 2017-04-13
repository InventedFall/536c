


// Constants for ChassisDrive-(Function to move & lift during Auton or Programming Skills.
const int Forwards = 1;
const int Backwards = 2;
const int TurnRight = 3;
const int TurnLeft = 4;
const int SweepRight = 5;
const int SweepLeft = 6;
const int BackSweepRight = 7;
const int BackSweepLeft = 8;
const int ForwardRight = 9;
const int ForwardLeft = 10;

//Constants for lift
const int down =1;
//const int deploy=500;
const int up=1800;

// ********************  Gyro & lift Constants   **********************************
// Add new constants used by Gyro functions
const int Turn = 11;  // Used with Gyro senor
const int Sweep = 12; // Used with Gyro senor
const int GyroError = 120;  // Used to make Gyro turns more accurate by stopping before endpoint
const int LiftError = 50; // Used to make lift more accurate by stopping before endpoint

// PROGRAM NOTE
//      GyroError is used to define the period of time between the robot stoping and the distance it travels
//      while it is drifting until it comes to a complete stop. This is due to the (Fast)Speed of the chasis
//      stoping at the desired endpoint but the momentum of the robot keeps it moving(Turning). This is
//      eliminated using the GyroError and helps with accuracy



void liftMotors ( int speed)
{

	motor[lift1]= speed;
	motor[lift2]= speed;
	motor[lift3]= speed;
	motor[lift4]= speed;//sets lift speeds in Chasis functions for lifting but also driver
	motor[lift5]= speed;
	motor[lift6]= speed;

}



// ****************  END NEW CODE   **********************************
void chassisDrive (int leftSpeed, int rightSpeed)
{
	motor[L1]=leftSpeed;
	motor[r1]=rightSpeed; //sets drive speeds in Chasis functions for lifting but also driver
	motor[L2]=leftSpeed;
	motor[r2]=rightSpeed;

}







// Function to determine whether to keep going or not.
// Assumption is endValue is always positive so convert currentValue to positive too
bool shouldWeKeepGoing(int currentValue, int endValue)
{
	bool shouldGo = true;

	if (abs(currentValue) >= abs(endValue))
	{
		shouldGo = false;
	}
	return shouldGo;

}

// ********************  NEW CODE   **********************************
// Function to determine whether to keep going or not when using GYRO.
// Positive/negative values are very important with gyro
// Can't use ABS (Absolute values)
// With right turns we will pass currentValue, endValue
// With left turns we will pass endValue, currentValue
bool shouldWeKeepGoingGyro(int currentValue, int endValue)
{
	bool shouldGo = true;

	if (currentValue >= endValue)
	{
		shouldGo = false;
	}
	return shouldGo;
}
// ****************  END NEW CODE   **********************************

// Function to control chassis motors



////////////////////////////////////////////////////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Function to move robot in specific directions
void robotFunction(int chassisDirection=0, int chassisSpeed=0, int chassisDistance=0,int liftHeight=0,int WaitTime=150,int clawo,int clawc, int LiftHoldSpeed=10, int DeploySolenoid=0)
{
	//********************(Clear Encoders)****************************
	SensorValue[frontRightEncoder] = 0;
	SensorValue[frontLeftEncoder]  = 0;
	//****************************************************************
	int shouldopen= 1200;
	// Define local variables
	bool isLiftMoving = false;
	//	int isWristMoving = 0;
	int leftSpeed = 0;
	int liftSpeed = 0;
	int rightSpeed = 0; // speed of motors for right side of chassis - is backward
	bool isChassisMoving = false; // Flag to determine if chassis moving routine should run

	int isRobotFunctionRunning = true; // Flag to determine if while loop should continue running
	// ********************  NEW CODE   **********************************
	int currentHeading = 0; // Gyro value of current heading
	// ****************  END NEW CODE   **********************************

	// Determine speeds of left and right side of robot
	switch (chassisDirection)
	{
	case Forwards:
		leftSpeed = chassisSpeed;
		rightSpeed = chassisSpeed;
		displayLCDString( 0,0, "Forward         ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontLeftEncoder]);
		break;
	case Backwards:
		leftSpeed = -chassisSpeed;
		rightSpeed = -chassisSpeed;
		displayLCDString(0, 0, "Backward        ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontLeftEncoder]);
		break;
	case TurnRight:
		leftSpeed = chassisSpeed;
		rightSpeed = -chassisSpeed;
		displayLCDString(0, 0, "TurnRight       ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontLeftEncoder]);
		break;
	case TurnLeft:
		leftSpeed = -chassisSpeed;
		rightSpeed = chassisSpeed;
		displayLCDString(0, 0, "TurnLeft        ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontLeftEncoder]);
		break;
	case SweepRight:
		leftSpeed = chassisSpeed;
		rightSpeed = 0;
		displayLCDString(0, 0, "SweepRight      ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontLeftEncoder]);
		break;
	case SweepLeft:
		leftSpeed = 0;
		rightSpeed = chassisSpeed;
		displayLCDString(0, 0, "SweepLeft       ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontRightEncoder]);
		break;
	case BackSweepRight:
		leftSpeed = 0;
		rightSpeed = -chassisSpeed;
		displayLCDString(0, 0, "BackSweepRight  ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontRightEncoder]);
		break;
	case BackSweepLeft:
		leftSpeed = -chassisSpeed;
		rightSpeed = 0;
		displayLCDString(0, 0, "BackSweepLeft   ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontLeftEncoder]);
		break;
	case ForwardRight:
		leftSpeed = chassisSpeed;
		rightSpeed = chassisSpeed*0.75;
		displayLCDString(0, 0, "ForwardRight    ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontLeftEncoder]);
		break;
	case ForwardLeft:
		leftSpeed = chassisSpeed*0.75;
		rightSpeed = chassisSpeed;
		displayLCDString(0, 0, "ForwardLeft     ");
		displayLCDNumber(1,1,chassisDistance);
		displayLCDNumber(1,10,SensorValue[frontLeftEncoder]);
		break;
		// ********************  NEW CODE   **********************************
		// Turn uses Gyro.
		// ChassisDistance will be the heading to turn to
		// GyroError helps make turns more accurate by using drift to finish turn
	case Turn:
		currentHeading = SensorValue[GyroSensor];   // Get current heading from gyro
		if (currentHeading + GyroError < chassisDistance) // Should we go right?
		{
			// Need to go to the right to reach destination
			leftSpeed = chassisSpeed;
			rightSpeed =-chassisSpeed;
			displayLCDString(0, 0, "Gyro Right Turn ");
			displayLCDNumber(1,1,chassisDistance);
			displayLCDNumber(1,10,SensorValue[GyroSensor]);
		} else if (currentHeading - GyroError > chassisDistance) // Should we go left?
		{
			// Need to go to the left to reach destination
			leftSpeed = -chassisSpeed;
			rightSpeed = chassisSpeed;
			displayLCDString(0, 0, "Gyro Left Turn  ");
			displayLCDNumber(1,1,chassisDistance);
			displayLCDNumber(1,10,SensorValue[GyroSensor]);
		} else // else already within the Error value of the direction. Don't move
		{
			leftSpeed = 0;
			rightSpeed = 0;
			chassisDirection = 0;
			displayLCDString(0, 0, "Gyro Nothing    ");
		}
		break;
	case Sweep:
		currentHeading = SensorValue[GyroSensor]; // Get current heading from gyro
		if (currentHeading + GyroError < chassisDistance) // Should we go right?
		{
			// Need to go to the right to reach destination
			leftSpeed = chassisSpeed;
			rightSpeed = 0;
			displayLCDString(0, 0, "Gyro Right Sweep Turn ");
			displayLCDNumber(1,1,chassisDistance);
			displayLCDNumber(1,10,SensorValue[GyroSensor]);
		} else if (currentHeading - GyroError > chassisDistance) // Should we go left?
		{
			// Need to go to the left to reach destination
			leftSpeed = 0;
			rightSpeed = chassisSpeed;
			displayLCDString(0, 0, "Gyro Left Sweep Turn  ");
			displayLCDNumber(1,1,chassisDistance);
			displayLCDNumber(1,10,SensorValue[GyroSensor]);
		} else // else already within the Error value of the direction. Don't move
		{
			leftSpeed = 0;
			rightSpeed = 0;
			chassisDirection = 0;
			displayLCDString(1, 0, "Gyro Nothing    ");


		}
		break;






		// ****************  END NEW CODE   **********************************
	default:
		leftSpeed = 0;
		rightSpeed = 0;
		displayLCDString(1, 0, "InvalidDirection");
		chassisDistance = 0;
	} // End Switch(chassisDirection)



	//determine liftspeeds

	if (SensorValue[ArmPot] < liftHeight-LiftError && liftHeight !=0)
	{
		liftSpeed =127;
		isLiftMoving = true;
		displayLCDNumber(0,0,SensorValue[ArmPot],10);
	}
	else if (SensorValue[ArmPot] > liftHeight+LiftError && liftHeight != 0)
	{
		liftSpeed =-127;
		isLiftMoving = true;
		displayLCDNumber(0,0,SensorValue[ArmPot],10);
	}
	else
	{
		liftSpeed = LiftHoldSpeed;
		isLiftMoving = false;
		displayLCDNumber(0,0,SensorValue[ArmPot],10);
	}

	if (SensorValue[CLAWW] > shouldopen)
	{
		SensorValue[solenoid] = clawo;
		SensorValue[solenoid2] = clawo;
	}
	else
	{
		SensorValue[solenoid] = clawc;
		SensorValue[solenoid2] = clawc;
	}

	SensorValue[solenoid3] = DeploySolenoid;

	// Check if robot is moving forward
	// ********************  NEW CODE   **********************************
	// Need to turn on isChassisMoving for Turns to heading 0
	//if (chassisDistance != 0)
	if (chassisDistance != 0 || chassisDirection == Turn || chassisDirection == Sweep)
		// ****************  END NEW CODE   **********************************
	{
		isChassisMoving = true;
		// ********************  NEW CODE   **********************************

		// ****************  END NEW CODE   **********************************
	}

	while(isRobotFunctionRunning)
	{
		if (isChassisMoving)
		{
			if (chassisDirection == SweepLeft || chassisDirection == BackSweepRight)
			{
				// Use rightEncoder because left motor is zero in these cases
				isChassisMoving = shouldWeKeepGoing(SensorValue[frontRightEncoder],chassisDistance);//current value , end value
			}
			// ********************  NEW CODE   **********************************
			// Add turn to While loop
			else if (chassisDirection == Turn ||chassisDirection == Sweep)
			{
				if (rightSpeed <= 0) // Indicates turning to the right. EndValue will be higher in this case
				{
					isChassisMoving = shouldWeKeepGoingGyro(SensorValue[GyroSensor] + GyroError,chassisDistance);
				} else // Indicates turning to the left. EndValue will be lower in this case
				{
					isChassisMoving = shouldWeKeepGoingGyro(chassisDistance,SensorValue[GyroSensor] - GyroError);
				}
			}
			// ****************  END NEW CODE   **********************************
			else {
				// Otherwise, use leftEGyroSensor
				isChassisMoving = shouldWeKeepGoing(SensorValue[frontLeftEncoder],chassisDistance);
			} // End of chassisDirection == SweepLeft...
		} else
		{
			leftSpeed = 0;
			rightSpeed = 0;
		} // End of is ChassisMoving

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(isLiftMoving)
		{
			if(liftSpeed > 0)
			{
				isLiftMoving = shouldWeKeepGoing(SensorValue[ArmPot], liftHeight-LiftError);


			}
			else
			{
				isLiftMoving = shouldWeKeepGoing(liftHeight+LiftError, SensorValue[ArmPot]);
			}
		}
		else
		{
			liftSpeed = 10;
		} //End of is LiftMoving
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		chassisDrive(rightSpeed, leftSpeed); // Set chassis motors one time
		liftMotors (liftSpeed);
		isRobotFunctionRunning = isChassisMoving + isLiftMoving;// + isWristMoving; // Should while loop continue?
	}  // End of While loop
	chassisDrive(0, 0); // Stop the robot
	liftMotors (10);



	wait1Msec(WaitTime);
} // End robotFunction



// Test of all chassisDirections
void testChassisDirections()
{


	//robotFunction (Forwards,127,600);

	//robotFunction (Backwards, 127, 600);

	//robotFunction (TurnRight,127,275);

	//robotFunction (TurnLeft,127,275);

	//robotFunction (SweepRight,127,275);

	//robotFunction (SweepLeft,127,275);

	//robotFunction (BackSweepRight,127,275);

	//robotFunction (BackSweepLeft,127,275);

	//robotFunction (ForwardLeft,127,275);

	//robotFunction (ForwardRight,127,275);
	//robotFunction(Forward, 127,900);
	//robotFunction(Backward, 127, 900);
	//robotFunction(TurnLeft, 127, 400);  // Out of order
	//robotFunction(TurnRight, 127, 400); // Out of order - Right first hits the bump

	//// ********************  NEW CODE   **********************************
	//robotFunction(Turn, 127, 1800); // Test Gyro Turn to 90 degress
	//robotFunction(Turn, 127, 900); 	// Test Gyro Turn to 180 degress
	//robotFunction(Turn, 127, 0); 		// Test Gyro Turn to 0 degress
	//robotFunction(Turn, 127, -1800);// Test Gyro Turn to -180 degress
	//robotFunction(Turn, 127, -900); // Test Gyro Turn to -90 degress
	//robotFunction(Turn, 127, 0); 		// Test Gyro Turn to 0 degress
	//robotFunction(Turn, 127, 0); 		// Test Gyro Nothin Turn

	//robotFunction(Sweep, 127, 1800); // Test Gyro Sweep Turn to 90 degress
	//robotFunction(Sweep, 127, 900); 	// Test Gyro Sweep Turn to 180 degress
	//robotFunction(Sweep, 127, 0); 		// Test Gyro Sweep Turn to 0 degress
	//robotFunction(Sweep, 127, -1800);// Test Gyro Sweep Turn to -180 degress
	//robotFunction(Sweep, 127, -900); // Test Gyro Sweep Turn to -90 degress
	//robotFunction(Sweep, 127, 0); 		// Test Gyro Sweep Turn to 0 degress
	//robotFunction(Sweep, 127, 0); 		// Test Gyro Nothin Turn

	//// ****************  END NEW CODE   **********************************

	//robotFunction(SweepRight, 127, 900);
	//robotFunction(SweepLeft, 127, 900);
	//robotFunction(BackSweepRight, 127, 900);
	//robotFunction(BackSweepLeft, 127, 900);
	//robotFunction(ForwardRight, 127, 900);
	//robotFunction(ForwardLeft, 127, 900);
	//robotFunction(0,127, 900);
}
