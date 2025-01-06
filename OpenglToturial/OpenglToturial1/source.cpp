#include <iostream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main(void)
{
    // GLFW 초기화
    if (!glfwInit())
    {
        std::cout << "GLFW 초기화 실패";
        glfwTerminate();
        return 1;
    }

    // GLFW 윈도우 속성 설정
    // Opengl버전
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core profile = No Backwards Compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
    if (!mainWindow)
    {
        std::cout << "GLFW 윈도우 생성 실패";
        glfwTerminate();
        return 1;
    }

    // Get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // GLEW를 사용하기 위한 컨텍스트 지정
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension features
    glewExperimental = GL_TRUE;

    if (!glewInit())
    {
        std::cout << "GLEW 초기화 실패";
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }
     
    // 뷰포트 사이즈 설정
    glViewport(0, 0, bufferWidth, bufferHeight);

    
    return 0;
}