#pragma once

#ifdef CM_PLATFORM_WINDOWS

extern Caveman::Application* Caveman::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Caveman::CreateApplication();
	app->Run();
	delete app;
}

#endif