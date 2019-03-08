#include "Application.h"
#include "View.h"
#include "TestCanvas.h"

int main(int argc, char ** argv)
{
	Application application;
	TestCanvas canvas = TestCanvas(&application);
	application.Init(&canvas, 800,600, "testTitle");
	application.Run();
	return 1;
}