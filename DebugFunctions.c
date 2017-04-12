
void clearLCD ()
{
	clearLCDLine(0);
	clearLCDLine(1);
}

//void nothingOnScreen ()
//{
//	displayLCDCenteredString(0,"Currently");
//	displayLCDCenteredString(1,"Empty");
//}


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


void swapAuton ()
{
	displayLCDCenteredString(0,"Autonomous");
	displayLCDCenteredString(1,"Swap");
	displayLCDNumber(0,14,autonomousMode,2);
	if (nLCDButtons == 2)
	{
		autonomousMode++;
		while(nLCDButtons == 2){wait1Msec(10);}
	}
	if (autonomousMode > 12)
	{
		autonomousMode = 1;
	}
}




void displayPotentiometerValue1 ()
{
	displayLCDCenteredString(0,"Arm Pot");
	displayLCDNumber(1,1,SensorValue[ArmPot],5);
}

void displayPotentiometerValue2 ()
{
	displayLCDCenteredString(0,"CLAWW");
	displayLCDNumber(1,1,SensorValue[CLAWW],5);
}



//void displayColorSensorValue()
//{
//	displayLCDCenteredString(0,"Color Sensor");
//		displayLCDNumber(1,6,SensorValue[light],4);
//}

//void displayUltrasonicValues ()
//{
//	displayLCDCenteredString(0,"Ultrasonics");
//	displayLCDNumber(1,2,SensorValue[leftSonar],4);
//		displayLCDNumber(1,9,SensorValue[rightSonar],4);
//}


void displayDigitalInputs ()//displays button inputs  (Function)
{
	displayLCDCenteredString(0,"Digital Inputs");
	displayLCDNumber(1,3,SensorValue[Touch],1);

}

void displaySmRdTemp ()
{
	displayLCDCenteredString(0,"Right Drive");
	//	 	SmartMotorSetSlewRate( L1,  100 ) ;
	sprintf( str, "%7.2f %7.2f", SmartMotorGetSpeed( r1 ), SmartMotorGetTemperature( r1 ));
	displayLCDString(1, 0, str);
}

void displaySmLdTemp ()
{
	displayLCDCenteredString(0,"Left Drive");
	 	 	SmartMotorSetSlewRate( L1,  100 ) ;
	sprintf( str, "%7.2f %7.2f", SmartMotorGetSpeed( L1 ), SmartMotorGetTemperature( L1 ));
	displayLCDString(1, 0, str);
}
void displaySmLfTemp ()
{
	displayLCDCenteredString(0,"Arm");
	//	 	SmartMotorSetSlewRate( lift2,  100 ) ;
	sprintf( str, "%7.2f %7.2f", SmartMotorGetSpeed( lift2 ), SmartMotorGetTemperature( lift2 ));
	displayLCDString(1, 0, str);
}

void displaySmLfCurrent ()
{
	displayLCDCenteredString(0,"Lift Current");
	//	 	SmartMotorSetSlewRate( lift2,  100 ) ;
	sprintf( str, "%7.2f %7.2f", SmartMotorGetCurrent (lift2, 1), SmartMotorGetTemperature( lift2 ));
	displayLCDString(1, 0, str);
}

void displaySmRdCurrent ()
{
	displayLCDCenteredString(0,"RightDR Current");
	//	 	SmartMotorSetSlewRate( lift2,  100 ) ;
	sprintf( str, "%7.2f %7.2f", SmartMotorGetCurrent( r1, 1 ), SmartMotorGetTemperature( r1 ));
	displayLCDString(1, 0, str);
}
