#pragma once

#include "LightCore/Core/Input.h"

namespace LightCore
{
	struct WindowsInput : public Input
	{
		WindowsInput();

		virtual void PollEvents() override;

		virtual void SetKeyPressed(int key, bool state) override;
		virtual int GetKeyState(int key) const override;

		bool m_Keys[512];
	};
}