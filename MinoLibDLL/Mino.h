#pragma once
#include "IMinoDevice.h"

namespace Mino {


	enum MINO_LINKTYPE {
		MINO_LINKTYPE_SHARED,
		MINO_LINKTYPE_STATIC
	};

	enum MINO_DEVICETYPE {
		MINO_DEVICETYPE_OPENGL3_0,
		MINO_DEVICETYPE_D3D9
	};

	IMinoDevice* getDevice(const MINO_LINKTYPE linktype, const MINO_DEVICETYPE device);


}