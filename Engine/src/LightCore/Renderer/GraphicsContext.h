#pragma once

struct __declspec(novtable) GraphicsContext
{
public:
	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;
	virtual void PrintContextInfo() = 0;

	virtual ~GraphicsContext() = default;
};