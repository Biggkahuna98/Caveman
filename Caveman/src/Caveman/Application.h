#pragma once

#include "Core.h"

namespace Caveman
{
	class CAVEMAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Define this in CLIENT
	Application* CreateApplication();
}
