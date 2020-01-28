#pragma once

#include "LightCore/Core/platform_input.h"

namespace LightCore
{
	struct win32_input : public platform_input
	{
		win32_input();

		virtual void PollEvents() override;

		virtual void SetKeyPressed(int key, bool state) override;
		virtual int GetKeyState(int key) const override;

		bool m_Keys[512];
	};
}