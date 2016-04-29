#include "\TURBOC3\PROJECTS\PIPES.H"

void operator >= (Component& c1,Component& c2)
{
	c2.inpress=c1.outpress;
	c1.inbackp=c2.outbackp;
	c2.inflow=c1.outflow;
	}
void Tee(Component& src,Component& c1,Component& c2)
{
	if((c1.outbackp==0 && c2.outbackp==0))
	{
		c1.inpress=c2.inpress=0;
		src.inbackp=0;
		c1.inflow = c2.inflow=0;
		return;
		}
	float f1 =(float)c1.outbackp;
	float f2 =(float)c2.outbackp;

	c1.inpress=src.outpress*f1;
	c2.inpress=src.outpress*f2;

	src.inbackp=c1.outbackp+c2.outbackp;

	c1.inflow=src.outflow*f1;
	c2.inflow=src.outflow*f2;
	}

void Pipe::Tick()
{
	outpress=(inpress<resist)?inpress:resist;
	outbackp=(inbackp<resist)?inbackp:resist;

	if(outpress<outbackp && outpress<resist)
	{
		outflow=outpress;
		}
	else if(outbackp < outpress && outpress<resist)
	       {
		outflow=outbackp;
		}
	else
	{
		outflow=resist;
	}
}
void Valve::Tick()
{
	if(status==on)
	{
		outpress=inpress;
		outbackp=inbackp;
		outflow=(outpress<outbackp)?outpress:outbackp;
		}
	else
	{
		outpress=0;
		outbackp=0;
		outflow=0;
		}
}
void Tank::Tick()
{
	outbackp=infinity;
	if(contents>0)
	{
		outpress=(maxoutpress<inbackp)? maxoutpress:inbackp;
		outflow=outpress;
		}
	else
	{
		outpress=0;
		outflow=0;
	}
	contents+=inflow-outflow;
	}
