//#include <iostream>
//#include <GLEW/glew.h>
//#include <GLFW/glfw3.h>
//// Window dimensions
//const GLint WIDTH = 800, HEIGHT = 600;
//
//int main(void)
//{
//    // GLFW 초기화
//    if (!glfwInit())
//    {
//        std::cout << "GLFW 초기화 실패";
//        glfwTerminate();
//        return 1;
//    }
//
//    // GLFW 윈도우 속성 설정
//    // Opengl버전
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    // Core profile = No Backwards Compatibility
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    // Allow forward compatibility
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
//    if (!mainWindow)
//    {
//        std::cout << "GLFW 윈도우 생성 실패";
//        glfwTerminate();
//        return 1;
//    }
//
//    // Get buffer size information
//    int bufferWidth, bufferHeight;
//    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
//
//    // GLEW를 사용하기 위한 컨텍스트 지정
//    glfwMakeContextCurrent(mainWindow);
//
//    // Allow modern extension features
//    glewExperimental = GL_TRUE;
//
//    if (!glewInit())
//    {
//        std::cout << "GLEW 초기화 실패";
//        glfwDestroyWindow(mainWindow);
//        glfwTerminate();
//        return 1;
//    }
//     
//    // 뷰포트 사이즈 설정
//    glViewport(0, 0, bufferWidth, bufferHeight);
//
//    
//    return 0;
//}

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib/glew32.lib")
#pragma comment(lib, "lib/glfw3.lib")



void window_resized(GLFWwindow* window, int width, int height);

void key_pressed(GLFWwindow* window, int key, int scancode, int action, int mods);
void show_glfw_error(int error, const char* description);


int main()
{
	glfwSetErrorCallback(show_glfw_error);


	if (!glfwInit()) {
		std::cerr << "GLFW 초기화 실패" << '\n';
		exit(-1);
	}


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


	GLFWwindow* window = glfwCreateWindow(
		800, // width
		600, // height
		"OpenGL Example",

		NULL, NULL);
	if (!window)
	{
		std::cerr << "윈도우 생성 실패" << '\n';
		glfwTerminate();
		exit(-1);
	}


	glfwMakeContextCurrent(window);


	glfwSetWindowSizeCallback(window, window_resized);
	glfwSetKeyCallback(window, key_pressed);


	glfwSwapInterval(1);


	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << "GLEW 초기화 실패 " << glewGetErrorString(err) << '\n';
		glfwTerminate();
		exit(-1);
	}


	std::cout << glGetString(GL_VERSION) << '\n';


	int nr_extensions = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &nr_extensions);

	for (int i = 0; i < nr_extensions; ++i) {
		std::cout << glGetStringi(GL_EXTENSIONS, i) << '\n';
	}


	glClearColor(0, 0, 1, 1);


	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}


	glfwDestroyWindow(window);


	glfwTerminate();
	return 0;
}

void show_glfw_error(int error, const char* description) {
	std::cerr << "Error: " << description << '\n';
}

void window_resized(GLFWwindow* window, int width, int height) {
	std::cout << "Window resized, new window size: " << width << " x " << height << '\n';

	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}

void key_pressed(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == 'Q' && action == GLFW_PRESS) {
		glfwTerminate();
		exit(0);
	}
}