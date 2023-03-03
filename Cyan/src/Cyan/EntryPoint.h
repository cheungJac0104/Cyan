#pragma once

#ifdef CY_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	auto app = Cyan::CreateApplication();
	app->Run();
	delete app;
}

#endif
