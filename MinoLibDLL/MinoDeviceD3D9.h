#pragma once
#include "IMinoDevice.h"

namespace Mino {


	class MinoDeviceD3D9 :
		public IMinoDevice
	{
	public:
		MinoDeviceD3D9();
		virtual ~MinoDeviceD3D9();
		virtual bool init(HWND hWnd) = 0;

	};

}