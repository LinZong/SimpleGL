#define GLEW_STATIC
#include "Bootstrap.h"
#include "Utils.h"
using namespace std;

int main(int argc,const char*argv[])
{
	auto window = InitGLFWEnvrionment(argc, argv);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.4f,0.8f,1.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}