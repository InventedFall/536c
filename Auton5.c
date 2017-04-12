void Auton5 () //block from left square  ---needs work/love !!TEST!!!!!!!!
{

	robotFunction(Forwards, 127, 600,250,0,1,1,0,1);//lift up open claw
//	robotFunction(Forwards, 0, 0,deploy,300,1,1);//lift up open claw
//	robotFunction(Forwards, 0, 0,down,0,1,1);//lift down close claw wait 500
	robotFunction(Forwards,127,998,500,0,1,1);
	robotFunction(Sweep, 127,300,500,0,1,1);
	robotFunction(Forwards,127,640,1000,0,1,1);

}
