#include "Mino.h"
#include "IMinoDevice.h"
#include <winbase.h>
#include <tchar.h>
#pragma comment(lib,"kernel32.lib")

#if MINO_USE_D3D9
#include "MinoDeviceD3D9.h"
#endif
namespace Mino {

	IMinoDevice* getDevice(const MINO_LINKTYPE linktype, const MINO_DEVICETYPE device) {

		if (linktype == MINO_LINKTYPE_STATIC) {

#if MINO_USE_D3D9
			if ( device == MINO_DEVICETYPE_D3D9 ) {
				return new MinoDeviceD3D9();
			}
#endif

		}
		else if (linktype == MINO_LINKTYPE_SHARED) {

			TCHAR szLibName[261];
			if (device == MINO_DEVICETYPE_D3D9) {
				if (szLibName) {
					_stprintf_s(szLibName, sizeof(szLibName), _T("MinoD3D9.lib"));
				}

			}

			if ( LoadLibrary(szLibName) ) {


			}

		}

		return 0;
	}


}