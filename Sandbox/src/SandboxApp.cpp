#include <LightCore.h>

struct Sandbox : public LightCore::Application
{
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