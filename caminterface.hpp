#pragma once
#include <iostream> 

namespace camViz {
	class CameraClient {
	public:
		virtual int getRefreshRate() = 0;
	protected:
		int refreshRate;
	};
}

