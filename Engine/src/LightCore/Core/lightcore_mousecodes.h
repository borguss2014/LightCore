#pragma once

#include <ostream>

namespace LightCore
{
	typedef enum class MouseKeyCode : uint16_t
	{
		Button1 = 0,
		Button2 = 1,
		Button3 = 2,
		Button4 = 3,
		Button5 = 4,
		Button6 = 5,
		Button7 = 6,
		Button8 = 7,
		ButtonLeft = Button1,
		ButtonRight = Button2,
		ButtonMiddle = Button3
	} MouseKey;

	inline std::ostream& operator<<(std::ostream& os, MouseKey keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}

// From glfw3.h

	// Mouse additional buttons
#define LC_MOUSE_BUTTON_1	::LightCore::MouseKey::Button1
#define LC_MOUSE_BUTTON_2   ::LightCore::MouseKey::Button2
#define LC_MOUSE_BUTTON_3   ::LightCore::MouseKey::Button3
#define LC_MOUSE_BUTTON_4   ::LightCore::MouseKey::Button4
#define LC_MOUSE_BUTTON_5   ::LightCore::MouseKey::Button5
#define LC_MOUSE_BUTTON_6   ::LightCore::MouseKey::Button6
#define LC_MOUSE_BUTTON_7   ::LightCore::MouseKey::Button7
#define LC_MOUSE_BUTTON_8   ::LightCore::MouseKey::Button8

	// Main mouse buttons
#define LC_MOUSE_BUTTON_LEFT	::LightCore::MouseKey::Button1
#define LC_MOUSE_BUTTON_RIGHT	::LightCore::MouseKey::Button2
#define LC_MOUSE_BUTTON_MIDDLE  ::LightCore::MouseKey::Button3
}