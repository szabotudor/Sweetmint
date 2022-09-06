#ifdef USE_X11
#include<X.h>
#endif

#include<Sweetmint.hpp>
#include<glad/glad.h>
#include<GLFW/glfw3.h>


void framebufferCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


namespace swm {
	Window::Window(uivec2 windowSize, char* windowTitle) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(windowSize.x, windowSize.y, windowTitle, NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glViewport(0, 0, windowSize.x, windowSize.y);
		glfwSetFramebufferSizeCallback(window, framebufferCallback);
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