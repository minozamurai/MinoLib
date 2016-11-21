#include "MinoDeviceD3D9.h"
#include "dxcommon.h"

namespace Mino {

	MinoDeviceD3D9::MinoDeviceD3D9()
	{
	}


	MinoDeviceD3D9::~MinoDeviceD3D9()
	{
	}


	bool MinoDeviceD3D9::init(HWND hWnd) {

		m_pD3D = Direct3DCreate9(D3D_SDK_VERSION); //Standard
												   // IDirect3D9コンポーネントの取得
		if (NULL == m_pD3D)
			return false;

		D3DCAPS9 Caps;
		m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &Caps);

		DWORD BehaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;

		// If device doesn't support HW T&L or doesn't support 1.1 vertex shaders in HW 
		// then switch to SWVP.
		if ((Caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) == 0 ||
			Caps.VertexShaderVersion < D3DVS_VERSION(2, 0))
		{
			BehaviorFlags = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		}

		ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));
		m_d3dpp.Windowed = TRUE;
		m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		m_d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
		m_d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
		m_d3dpp.MultiSampleQuality = 0;
		m_d3dpp.EnableAutoDepthStencil = TRUE;
		m_d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

		for (int m = 0; m <= (int)D3DMULTISAMPLE_4_SAMPLES; m += 2)
		{
			DWORD QualityBackBuffer = 0;

			HRESULT hr = m_pD3D->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				m_d3dpp.BackBufferFormat,
				m_d3dpp.Windowed,
				(D3DMULTISAMPLE_TYPE)m,
				&QualityBackBuffer);
			if (FAILED(hr)) break;

			if (QualityBackBuffer > 0)
			{
				m_d3dpp.MultiSampleType = (D3DMULTISAMPLE_TYPE)m;
				m_d3dpp.MultiSampleQuality = QualityBackBuffer - 1;
			}
		}

		// Hardware Device
		hr = m_pD3D->CreateDevice(
			D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, winId(),
			BehaviorFlags, &m_d3dpp, &m_pDevice);

		if (FAILED(hr))
		{
			m_d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
			m_d3dpp.MultiSampleQuality = 0;
			// Reference Rasterizer
			hr = m_pD3D->CreateDevice(
				D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, winId(),
				D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_d3dpp, &m_pDevice);
		}

	}



	void MinoDeviceD3D9::terminate() {

		SAFE_RELEASE(m_pDevice);
		SAFE_RELEASE(m_pD3D);

	}

}