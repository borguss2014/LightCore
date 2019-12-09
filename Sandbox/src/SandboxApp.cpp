#include <LightCore.h>
#include <LightCore/Core/EntryPoint.h>

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