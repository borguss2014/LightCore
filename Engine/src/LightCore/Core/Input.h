#pragma once

namespace LightCore
{
	/* TODO(Cristian): This shouldn't be an interface. 
	*  Platform independent operations should take place here, and decide
	*  implementation usage based on current platform
 	*/
	struct __declspec(novtable) Input
	{
	public:
		virtual void PollEvents() = 0;

		virtual void SetKeyPressed(int key, bool state) = 0;
		virtual int GetKeyState(int key) const = 0;

		virtual ~Input() = default;
	};

}