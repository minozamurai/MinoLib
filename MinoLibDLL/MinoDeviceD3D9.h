#pragma once
#include "IMinoDevice.h"
#include <d3d9.h>

namespace Mino {


	class MinoDeviceD3D9 :
		public IMinoDevice
	{
	private:
		IDirect3D9* m_pD3D;
		IDirect3DDevice9* m_pDevice;
	public:
		MinoDeviceD3D9();
		virtual ~MinoDeviceD3D9();
		bool init(HWND hWnd);
		void terminate();
		void reset();
	};

}