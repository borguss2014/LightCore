#pragma once

namespace LightCore
{
	struct platform_input
	{
		virtual ~platform_input() = default;

		virtual void PollEvents() = 0;
		virtual void SetKeyPressed(int key, bool state) = 0;
		virtual int GetKeyState(int key) const = 0;
	};
}