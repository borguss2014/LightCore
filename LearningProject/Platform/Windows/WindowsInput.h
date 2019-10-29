#pragma once

#include "../../LightCore/Core/Input.h"

class WindowsInput : public Input
{
public:
	WindowsInput();

	virtual void PollEvents() override;

	virtual void SetKeyPressed(int key) override;
	virtual void SetKeyReleased(int key) override;
	virtual void SetKeyStatus() override;

	virtual void DispatchEvents() override;
private:
	bool m_Keys[256];
};