#pragma once

#ifdef CM_PLATFORM_WINDOWS

extern Caveman::Application* Caveman::CreateApplication();

int main(int argc, char** argv)
{
	Caveman::Logger::Init();
	CM_ENGINE_WARN("Initialized Engine Logger");
	CM_INFO("Initialized Client Logger");

	auto app = Caveman::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif