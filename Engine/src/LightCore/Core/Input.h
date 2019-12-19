#pragma once

namespace LightCore
{

	struct __declspec(novtable) Input
	{
	public:
		virtual void PollEvents() = 0;

		virtual void SetKeyPressed(int key) = 0;
		virtual void SetKeyReleased(int key) = 0;

		virtual int GetKeyState(int key) const = 0;

		virtual void DispatchEvents() = 0;

		virtual ~Input() = default;
	};

}