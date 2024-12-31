#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glClearColor(0, 0, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glViewport(0, 0, 640, 480);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.f, 1.f, 0.f);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.5f, 0.f, 0.f);
        glVertex3f(-0.5f, 0.f, 0.f);
        glVertex3f(0.f, 1.f, 0.f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}