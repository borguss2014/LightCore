#pragma once

class __declspec(novtable) GraphicsContext
{
public:
	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;

	virtual ~GraphicsContext() = default;
};