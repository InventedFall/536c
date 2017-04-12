

void Auton8 ()//left side 2 stars?
{
	robotFunction(Forwards, 127, 0,250,0,1,1,0,1);//lift up open claw

	robotFunction(Forwards, 127, 1536,1,0,1,1,-5);//lift down close claw wait 500
	//robotFunction(Forwards,127,1536,1,0,1,1);//forward 1000, lift 0, wait 0, open claw

	robotFunction(Forwards, 0, 0,1,150,0,0);// close claw + wait 300(changed to 150)(may need to be reverted)
	robotFunction(Forwards, -127, 614,800,0,0,0);// backup 400, lift 800, wait 0, close claw
	robotFunction(Sweep, 127,1100,800,0,0,0);//gyro turn to -1100, lift 800, claw closed
	robotFunction(Forwards,-127,1433,800,0,0,0);//backwards 1100, lift 800, wait 150, claw closed
	robotFunction(Forwards, 0, 0,up,0,1,0);//lift up, wait 150, open claw midway
	robotFunction(Forwards, 0, 0,1,0,1,1);//realign-tchnically, turn to ____,lift down(0), open claw/////////////////////////add gyro count that aligns with perimeter wall/////////////
	robotFunction(Forwards,127,998,1,300,1,1);//forwards 650,llift down,wait 300, open claw
	robotFunction(Forwards, 0, 0,1,300,0,0);//close claw+wait 300
	robotFunction(Forwards,-127,1383,600,0,0,0);//backup 900, lift 600, claw closed
	robotFunction(Forwards, 0, 0,up,300,0,1);//lift up, open claw, wait 300
		robotFunction(Forwards, 0, 0,1,0,1,1);//realign-tchnically, turn to ____,lift down(0), open claw/////////////////////////add gyro count that aligns with perimeter wall/////////////
	robotFunction(Forwards,127,998,1,300,1,1);//forwards 650,llift down,wait 300, open claw
	robotFunction(Forwards, 0, 0,1,300,0,0);//close claw+wait 300
	robotFunction(Forwards,-127,1383,600,0,0,0);//backup 900, lift 600, claw closed
	robotFunction(Forwards, 0, 0,up,300,0,1);//lift up, open claw, wait 300
}
