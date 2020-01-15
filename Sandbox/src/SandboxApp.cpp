#include <LightCore.h>

struct Sandbox : public LightCore::platform_application
{
	Sandbox()
	{
		
	}

	~Sandbox()
	{

	}
};

/* TODO(Cristian): Should have an actual main entry point here
*/
LightCore::platform_application* LightCore::CreateApplication()
{
	return new Sandbox();
}