#include <GL/gl.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <system_error>

using namespace std;

void error_callback(int error, const char* description)
{
    cerr << description << endl;
}

int main (int argc, char** argv)
{
    cout << "Hello World" << endl;

    if (!glfwInit()) {
	cerr << "Failed to initialize GLFW." << endl;
	return -1;
    }
    glfwSetErrorCallback(&error_callback);

    // Creating a window
    GLFWwindow *pWindow = glfwCreateWindow(640, 480, "Oat", NULL, NULL);
    if (!pWindow) {
	cerr << "Failed to create window or OpenGL context." << endl;
	return -1;
    }

    glfwMakeContextCurrent(pWindow);

    while(!glfwWindowShouldClose(pWindow)) {
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(pWindow);

	glfwPollEvents();
    }
    
    
    glfwTerminate();
    return 0;  
}
