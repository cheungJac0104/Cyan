#pragma once

#include "Core.h"

namespace Cyan{
	class CYAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in CLIENT
	Application* CreateApplication();
}


