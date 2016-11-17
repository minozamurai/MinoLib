#pragma once
#include <Windows.h>

namespace Mino {
	class IMinoDevice {


	public:
		virtual bool init(HWND hWnd) = 0;
	};

}