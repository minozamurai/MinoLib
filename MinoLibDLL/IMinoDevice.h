#pragma once
#include <Windows.h>

namespace Mino {
	class IMinoDevice {


	public:
		virtual bool init(HWND hWnd) = 0;
		virtual void terminate() = 0;
		virtual void reset() = 0;
	};

}