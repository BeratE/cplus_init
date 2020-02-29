#include <GL/gl.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <system_error>
#include "config.hpp"

using namespace std;

void error_callback(int error, const char* description)
{
    printf("Error - %s", description);
}

void key_callback(GLFWwindow* pWindow, int key, int scancode, int action, int mods)
{
    printf("Key Event - Key: %d, Scancode: %d, Action: %d, Mods: %d\n", key, scancode, action, mods);
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
}

void framebuffersize_callback(GLFWwindow* pWindow, int width, int height)
{
    printf("Resize - Width: %d, Height: %d\n", width, height);
    glViewport(0, 0, width, height);
}

int main (int argc, char** argv)
{
    cout << "Hello World" << endl;

    int versionMajor, versionMinor, versionRev;
    glfwGetVersion(&versionMajor, &versionMinor, &versionRev);
    printf("GLFW Version %d.%d.%d\n", versionMajor, versionMinor, versionRev);

    glfwSetErrorCallback(&error_callback);
    
    if (!glfwInit()) {
	cerr << "Failed to initialize GLFW." << endl;
	return -1;
    }

    // Creating a window
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
    GLFWwindow *pWindow = glfwCreateWindow(640, 480, "Oat", NULL, NULL);
    if (!pWindow) {
	cerr << "Failed to create window or OpenGL context." << endl;
	return -1;
    }
    printf("OpenGL Version %d.%d Core \n", OPENGL_VERSION_MAJOR, OPENGL_VERSION_MINOR);
    
    glfwMakeContextCurrent(pWindow);
    glfwSetKeyCallback(pWindow, &key_callback);
    glfwSetFramebufferSizeCallback(pWindow, &framebuffersize_callback);

    while(!glfwWindowShouldClose(pWindow)) {
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(pWindow);

	glfwPollEvents();
    }
    
    
    glfwTerminate();
    return 0;  
}
