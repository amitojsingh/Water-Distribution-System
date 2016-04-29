//#include "\TURBOC3\PROJECTS\PIPES.H"
#include "\TURBOC3\PROJECTS\PIPES.CPP"
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>

int main()
{
	Source src(100);
	Pipe pipe1(80);
	Valve valve1(on);

	Tank tank1(60);
	Switch switch1(&tank1,300);
	Switch switch2(&tank1, 50);

	Pipe pipe2(80);
	Sink sink1(30);
	Pipe pipe3(40);
	Valve valve2(on);

	Tank tank2(80);
	Switch switch3(&tank2, 250);
	Switch switch4(&tank2, 50);

	Sink sink2(20);

	while( !kbhit() )
	{
		src>=pipe1;
		pipe1>=valve1;
		valve1>=tank1;
		Tee(tank1,pipe2,pipe3);
		pipe2>=sink1;
		pipe3>=valve2;
		valve2>=tank2;
		tank2>=sink2;

		src.Tick();
		pipe1.Tick();
		valve1.Tick();
		tank1.Tick();
		switch1.Tick();
		switch2.Tick();
		pipe2.Tick();
		sink1.Tick();
		pipe3.Tick();
		valve2.Tick();
		tank2.Tick();
		switch3.Tick();
		switch4.Tick();
		sink2.Tick();
		if(valve1.Status()==on&& switch1.Status()==on)
			valve1.Status()=off;
		if (valve1.Status()==off && switch2.Status()==off)
			valve1.Status()=on;
		if(valve2.Status()==on && switch3.Status()==on)
			valve2.Status()=off;
		if(valve2.Status()==off && switch4.Status()==off)
			valve2.Status()=on;
		cout<<" Src=" <<setw(2)<<src.Flow();
		cout<<" p1="<<setw(2)<<pipe1.Flow();

		if(valve1.Status()==off)
			cout<<" v1=off";
		else
			cout<<" v1=on";

		cout<<" T1="<<setw(3)<<tank1.Contents();
		cout<<" p2="<<setw(2)<<pipe2.Flow();
		cout<<" Sink1= "<<setw(2)<<sink1.Flow();
		cout<<" p3="<<setw(2)<<pipe3.Flow();
		if(valve2.Status()==off)
			cout<<" v2=off";
		else
		cout<<" v2=on";
		cout<<" T2= "<<setw(3)<<tank2.Contents();
		cout<<" sink2= "<<setw(2)<<sink2.Flow();
		cout<<"\n";
	}
		return 0;
}

