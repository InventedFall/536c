void Auton3 ()//left side 2 stars ---needs work/love !!reminder!! ---muliply encoder value by .6
{
		wait1Msec(5000);
	robotFunction (Forwards,-127,768,0,0,0,0);//backwards
	//robotFunction(Forwards, 0, 0,deploy,500,1,1);//lift up open claw
	robotFunction(Forwards, 127, 0,250,0,1,1,0,1);//lift up open claw
	robotFunction(Forwards, 0, 0,1,500,0,0);//lift down close claw wait 500
	robotFunction(Forwards,127,998,1,150,1,1);//forward 1000, lift 0, wait 0, open claw
	robotFunction(Forwards, 0, 0,1,300,0,0);//close claw
	robotFunction(Forwards,-127,384,900,150,0,0);//backwards
	robotFunction(Turn, 127,780,950,150,0,0);
	robotFunction(Forwards,-127,1536,950,150,0,0);
	robotFunction(Forwards, 0, 0,up,0,0,1);//lift up, wait 150, open claw midway

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
