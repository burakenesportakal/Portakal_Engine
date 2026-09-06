#pragma once

#include "Core.h"

namespace Portakal {
	class PRTKL_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	Application* CreateApplication(); //Defined in CLIENT
}


