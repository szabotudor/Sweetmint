#ifdef USE_X11
#include<X.h>
#endif

#include "Sweetmint.h"


void framebufferCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


namespace swm {
	Window::Window(uivec2 windowSize, const char* windowTitle) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(windowSize.x, windowSize.y, windowTitle, NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glViewport(0, 0, windowSize.x, windowSize.y);
		glfwSetFramebufferSizeCallback(window, framebufferCallback);
	}

	void Window::setClearColor(Color col) {
		fColor c{col};
		glClearColor(c.r, c.g, c.b, c.a);
	}

	void Window::clear() {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	bool Window::shouldClose() {
		glfwSwapBuffers(window);
		glfwPollEvents();
		return glfwWindowShouldClose(window);
	}

	Window::~Window() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}
