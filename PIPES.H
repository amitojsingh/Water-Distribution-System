const int infinity=32767;
enum offon{off,on};
class Tank;
class Component
{
protected:
	int inpress,outpress;
	int inbackp, outbackp;
	int inflow,outflow;
public:
	Component()
	{
		inpress = outpress = inbackp = outbackp = inflow = outflow = 0;
		}
	int Flow()
	{
		return inflow;
		}
	friend void operator >= (Component&,Component&);
	friend void Tee(Component&,Component&,Component&);
};

class Source:public Component
{
	public:
		Source(int outp)
		{
			outpress = inpress = outp;
			}
		void Tick()
		{
			outbackp=inbackp;
			outflow=(outpress<outbackp)?outpress : outbackp;
			inflow=outflow;
			}
};
class Sink:public Component
{
	public:
		Sink(int obp)
		{
			outbackp=inbackp=obp;
			}
		void Tick()
		{
			outpress=inpress;
			outflow=(outbackp<outpress)? outbackp:outpress;
			inflow=outflow;
			}
};
class Pipe:public Component
{
	private:
		int resist;
	public:
		Pipe(int r)
		{
			inbackp=resist=r;
			}
		void Tick();
};
class Valve:public Component
{
	private:
		offon status;
	public:
		Valve(offon s)
		{
			status=s;
			}
		offon& Status()
		{
			return status;
			}
		void Tick();
};
class Tank:public Component
{
	private:
		int contents;
		int maxoutpress;
	public:
		Tank(int mop)
		{
			maxoutpress=mop;
			contents=0;
			}
			int Contents()
			{
				return(contents);
				}
			void Tick();
};
class Switch
{
	private:
		offon status;
		int cap;
		Tank* tankptr;
	public:
		Switch(Tank *tptr,int tcap)
		{
			tankptr=tptr;
			cap=tcap;
			status=off;
			}
		int Status(void)
		{
			return(status);
			}
		void Tick(void)
		{
			status=(tankptr->Contents()>cap) ? on:off;
			}
};





