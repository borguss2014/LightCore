#pragma once
#include <ostream>

namespace LightCore
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define LC_KEY_SPACE           ::LightCore::Key::Space
#define LC_KEY_APOSTROPHE      ::LightCore::Key::Apostrophe    /* ' */
#define LC_KEY_COMMA           ::LightCore::Key::Comma         /* , */
#define LC_KEY_MINUS           ::LightCore::Key::Minus         /* - */
#define LC_KEY_PERIOD          ::LightCore::Key::Period        /* . */
#define LC_KEY_SLASH           ::LightCore::Key::Slash         /* / */
#define LC_KEY_0               ::LightCore::Key::D0
#define LC_KEY_1               ::LightCore::Key::D1
#define LC_KEY_2               ::LightCore::Key::D2
#define LC_KEY_3               ::LightCore::Key::D3
#define LC_KEY_4               ::LightCore::Key::D4
#define LC_KEY_5               ::LightCore::Key::D5
#define LC_KEY_6               ::LightCore::Key::D6
#define LC_KEY_7               ::LightCore::Key::D7
#define LC_KEY_8               ::LightCore::Key::D8
#define LC_KEY_9               ::LightCore::Key::D9
#define LC_KEY_SEMICOLON       ::LightCore::Key::Semicolon     /* ; */
#define LC_KEY_EQUAL           ::LightCore::Key::Equal         /* = */
#define LC_KEY_A               ::LightCore::Key::A
#define LC_KEY_B               ::LightCore::Key::B
#define LC_KEY_C               ::LightCore::Key::C
#define LC_KEY_D               ::LightCore::Key::D
#define LC_KEY_E               ::LightCore::Key::E
#define LC_KEY_F               ::LightCore::Key::F
#define LC_KEY_G               ::LightCore::Key::G
#define LC_KEY_H               ::LightCore::Key::H
#define LC_KEY_I               ::LightCore::Key::I
#define LC_KEY_J               ::LightCore::Key::J
#define LC_KEY_K               ::LightCore::Key::K
#define LC_KEY_L               ::LightCore::Key::L
#define LC_KEY_M               ::LightCore::Key::M
#define LC_KEY_N               ::LightCore::Key::N
#define LC_KEY_O               ::LightCore::Key::O
#define LC_KEY_P               ::LightCore::Key::P
#define LC_KEY_Q               ::LightCore::Key::Q
#define LC_KEY_R               ::LightCore::Key::R
#define LC_KEY_S               ::LightCore::Key::S
#define LC_KEY_T               ::LightCore::Key::T
#define LC_KEY_U               ::LightCore::Key::U
#define LC_KEY_V               ::LightCore::Key::V
#define LC_KEY_W               ::LightCore::Key::W
#define LC_KEY_X               ::LightCore::Key::X
#define LC_KEY_Y               ::LightCore::Key::Y
#define LC_KEY_Z               ::LightCore::Key::Z
#define LC_KEY_LEFT_BRACKET    ::LightCore::Key::LeftBracket   /* [ */
#define LC_KEY_BACKSLASH       ::LightCore::Key::Backslash     /* \ */
#define LC_KEY_RIGHT_BRACKET   ::LightCore::Key::RightBracket  /* ] */
#define LC_KEY_GRAVE_ACCENT    ::LightCore::Key::GraveAccent   /* ` */
#define LC_KEY_WORLD_1         ::LightCore::Key::World1        /* non-US #1 */
#define LC_KEY_WORLD_2         ::LightCore::Key::World2        /* non-US #2 */

/* Function keys */
#define LC_KEY_ESCAPE          ::LightCore::Key::Escape
#define LC_KEY_ENTER           ::LightCore::Key::Enter
#define LC_KEY_TAB             ::LightCore::Key::Tab
#define LC_KEY_BACKSPACE       ::LightCore::Key::Backspace
#define LC_KEY_INSERT          ::LightCore::Key::Insert
#define LC_KEY_DELETE          ::LightCore::Key::Delete
#define LC_KEY_RIGHT           ::LightCore::Key::Right
#define LC_KEY_LEFT            ::LightCore::Key::Left
#define LC_KEY_DOWN            ::LightCore::Key::Down
#define LC_KEY_UP              ::LightCore::Key::Up
#define LC_KEY_PAGE_UP         ::LightCore::Key::PageUp
#define LC_KEY_PAGE_DOWN       ::LightCore::Key::PageDown
#define LC_KEY_HOME            ::LightCore::Key::Home
#define LC_KEY_END             ::LightCore::Key::End
#define LC_KEY_CAPS_LOCK       ::LightCore::Key::CapsLock
#define LC_KEY_SCROLL_LOCK     ::LightCore::Key::ScrollLock
#define LC_KEY_NUM_LOCK        ::LightCore::Key::NumLock
#define LC_KEY_PRINT_SCREEN    ::LightCore::Key::PrintScreen
#define LC_KEY_PAUSE           ::LightCore::Key::Pause
#define LC_KEY_F1              ::LightCore::Key::F1
#define LC_KEY_F2              ::LightCore::Key::F2
#define LC_KEY_F3              ::LightCore::Key::F3
#define LC_KEY_F4              ::LightCore::Key::F4
#define LC_KEY_F5              ::LightCore::Key::F5
#define LC_KEY_F6              ::LightCore::Key::F6
#define LC_KEY_F7              ::LightCore::Key::F7
#define LC_KEY_F8              ::LightCore::Key::F8
#define LC_KEY_F9              ::LightCore::Key::F9
#define LC_KEY_F10             ::LightCore::Key::F10
#define LC_KEY_F11             ::LightCore::Key::F11
#define LC_KEY_F12             ::LightCore::Key::F12
#define LC_KEY_F13             ::LightCore::Key::F13
#define LC_KEY_F14             ::LightCore::Key::F14
#define LC_KEY_F15             ::LightCore::Key::F15
#define LC_KEY_F16             ::LightCore::Key::F16
#define LC_KEY_F17             ::LightCore::Key::F17
#define LC_KEY_F18             ::LightCore::Key::F18
#define LC_KEY_F19             ::LightCore::Key::F19
#define LC_KEY_F20             ::LightCore::Key::F20
#define LC_KEY_F21             ::LightCore::Key::F21
#define LC_KEY_F22             ::LightCore::Key::F22
#define LC_KEY_F23             ::LightCore::Key::F23
#define LC_KEY_F24             ::LightCore::Key::F24
#define LC_KEY_F25             ::LightCore::Key::F25

/* Keypad */
#define LC_KEY_KP_0            ::LightCore::Key::KP0
#define LC_KEY_KP_1            ::LightCore::Key::KP1
#define LC_KEY_KP_2            ::LightCore::Key::KP2
#define LC_KEY_KP_3            ::LightCore::Key::KP3
#define LC_KEY_KP_4            ::LightCore::Key::KP4
#define LC_KEY_KP_5            ::LightCore::Key::KP5
#define LC_KEY_KP_6            ::LightCore::Key::KP6
#define LC_KEY_KP_7            ::LightCore::Key::KP7
#define LC_KEY_KP_8            ::LightCore::Key::KP8
#define LC_KEY_KP_9            ::LightCore::Key::KP9
#define LC_KEY_KP_DECIMAL      ::LightCore::Key::KPDecimal
#define LC_KEY_KP_DIVIDE       ::LightCore::Key::KPDivide
#define LC_KEY_KP_MULTIPLY     ::LightCore::Key::KPMultiply
#define LC_KEY_KP_SUBTRACT     ::LightCore::Key::KPSubtract
#define LC_KEY_KP_ADD          ::LightCore::Key::KPAdd
#define LC_KEY_KP_ENTER        ::LightCore::Key::KPEnter
#define LC_KEY_KP_EQUAL        ::LightCore::Key::KPEqual

#define LC_KEY_LEFT_SHIFT      ::LightCore::Key::LeftShift
#define LC_KEY_LEFT_CONTROL    ::LightCore::Key::LeftControl
#define LC_KEY_LEFT_ALT        ::LightCore::Key::LeftAlt
#define LC_KEY_LEFT_SUPER      ::LightCore::Key::LeftSuper
#define LC_KEY_RIGHT_SHIFT     ::LightCore::Key::RightShift
#define LC_KEY_RIGHT_CONTROL   ::LightCore::Key::RightControl
#define LC_KEY_RIGHT_ALT       ::LightCore::Key::RightAlt
#define LC_KEY_RIGHT_SUPER     ::LightCore::Key::RightSuper
#define LC_KEY_MENU            ::LightCore::Key::Menu