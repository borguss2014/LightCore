#include <LightCore.h>

class Sandbox : public LightCore::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{

	}
};

LightCore::Application* LightCore::CreateApplication()
{
	return new Sandbox();
}