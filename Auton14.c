

void Auton14 ()
{

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


		robotFunction(Forwards, 127, 1075, 600,150,1,1);////forward, open claw
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//first delpoy + dump
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////v///////////////////////
	//robotFunction(Forwards, -127, 614,0,150,0,0);//back up 400  !!Warning!! this may not hit the target liftheigt, if it does not, chage value for lift!!
	////robotFunction(Forwards, 0, 0,deploy,500,1,1);// lift up 500, open claw
	//robotFunction(Forwards, 127, 0,250,0,1,1,0,1);//lift up open claw
	//robotFunction(Forwards, 0, 0,down,150,1,1); //down lift,
	//robotFunction (Forwards,127,461,down,150,1,1);////////////////////////forwards to load
	wait1Msec(500);//wait to load
	robotFunction(Forwards, -127, 1536, 600,0,0,0);//backup
	robotFunction(Forwards, 0, 0, up,150,0,1);//lift +claw DUUMPP
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//second dump
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	robotFunction(Turn, 127, 0, 200,150,1,1);//------// turn to zero, lift 200
	robotFunction(Forwards, 127, 1075, 600,150,1,1);////forward, open claw
	wait1Msec(500);//wait to load
	robotFunction(Forwards, 0, 0,600,150,0,0);//close claw
	robotFunction(Forwards, -127, 1075, 600,150,0,0);//backup 700, lift 300
	robotFunction(Forwards, 0, 0, up,150,0,1);//up+open claw
	wait1Msec(500);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//third dump
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		robotFunction(Turn, 127, 0, 200,150,1,1);//------// turn to zero, lift 200
	robotFunction(Forwards, 127, 1075, 600,150,1,1);////forward, open claw
	wait1Msec(500);//wait to load
	robotFunction(Forwards, 0, 0,600,150,0,0);//close claw
	robotFunction(Forwards, -127, 1075, 600,150,0,0);//backup 700, lift 300
	robotFunction(Forwards, 0, 0, up,150,0,1);//up+open claw
	wait1Msec(500);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//4th dump
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//robotFunction(Turn, 127, 0, 200,150,1,1);//------// turn to zero, lift 200
	//robotFunction(Forwards, 127, 1075, 600,150,1,1);////forward, open claw
	//wait1Msec(500);//wait to load
	//robotFunction(Forwards, 0, 0,600,150,0,0);//close claw
	//robotFunction(Forwards, -127, 1075, 600,150,0,0);//backup 700, lift 300
	//robotFunction(Forwards, 0, 0, up,150,0,1);//up+open claw
	//wait1Msec(500);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//turn grab 3 stars +cube and dump
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	robotFunction(Turn,127, 800, 500, 150,0,0);//////////////

	robotFunction(Forwards, -127, 768,500,150,0,0);
	robotFunction(Forwards, 127, 1536,down,500,1,1);
	robotFunction(Forwards, 0, 0,down,0,0,0);
	wait1Msec(500);
	robotFunction(Turn, 63, 50, 600,150,0,0);
	robotFunction(Forwards,- 127, 461,600,150,1,1);
	//		robotFunction(Forwards, 0, 0,0,1,1);
	robotFunction(Forwards, 0, 0, up,150,0,1);
		robotFunction(Forwards, 0, 0,down,0,1,1);
			robotFunction(Forwards,127,900,1,300,1,1);//forwards 650,llift down,wait 300, open claw
				robotFunction(Forwards, 0, 0,1,300,0,0);//close claw+wait 300
	robotFunction(Forwards,-127,1200,600,0,0,0);//backup 900, lift 600, claw closed
	robotFunction(Forwards, 0, 0,up,300,0,1);//lift up, open claw, wait 300


}
