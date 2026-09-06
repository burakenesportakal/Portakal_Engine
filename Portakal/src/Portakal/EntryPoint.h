#pragma once

#ifdef PRTKL_PLATFORM_WINDOWS

extern Portakal::Application* Portakal::CreateApplication();

int main(int argc, char** argv) {
	
	auto app = Portakal::CreateApplication();
	app->Run();
	delete app;
	}

#else 
#error Portakal Engine only support windows :D

#endif PRTKL_PLATFORM_WINDOWS