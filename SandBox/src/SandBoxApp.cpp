#include <Cyan.h>

class SandBox : public Cyan::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

void main() 
{
	SandBox* sandbox = new SandBox();
	sandbox->Run();
	delete sandbox;
}