#pragma once

#ifdef CY_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	Cyan::Log::Init();
	CY_CORE_ERROR("hELLO sON");
	CY_INFO("yES mASTER");

	auto app = Cyan::CreateApplication();
	app->Run();
	delete app;
}

#endif
