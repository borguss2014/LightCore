#pragma once
class Input
{
public: 
	virtual ~Input() = 0;

	virtual void PollEvents() = 0;

	virtual void SetKeyPressed(int key) = 0;
	virtual void SetKeyReleased(int key) = 0;
	virtual void SetKeyStatus() = 0;

	virtual void DispatchEvents() = 0;
};