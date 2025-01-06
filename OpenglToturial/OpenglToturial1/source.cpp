#include <iostream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main(void)
{
    // GLFW �ʱ�ȭ
    if (!glfwInit())
    {
        std::cout << "GLFW �ʱ�ȭ ����";
        glfwTerminate();
        return 1;
    }

    // GLFW ������ �Ӽ� ����
    // Opengl����
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core profile = No Backwards Compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
    if (!mainWindow)
    {
        std::cout << "GLFW ������ ���� ����";
        glfwTerminate();
        return 1;
    }

    // Get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // GLEW�� ����ϱ� ���� ���ؽ�Ʈ ����
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension features
    glewExperimental = GL_TRUE;

    if (!glewInit())
    {
        std::cout << "GLEW �ʱ�ȭ ����";
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }
     
    // ����Ʈ ������ ����
    glViewport(0, 0, bufferWidth, bufferHeight);

    
    return 0;
}