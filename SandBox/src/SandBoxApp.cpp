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

Cyan::Application* Cyan::CreateApplication()
{
	return new SandBox();
}