#define GLEW_STATIC
#include "Bootstrap.h"
#include "Utils.h"
#include <iostream>
using namespace std;

int main(int argc,const char*argv[])
{
	auto window = InitGLFWEnvrionment(argc, argv);
	GLfloat* colorArr = ParseColorString("#66CCFF");
	for(int i=0;i<3;++i)
	{
		cout << (float)colorArr[i] << " ";
	}
	cout << endl;
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