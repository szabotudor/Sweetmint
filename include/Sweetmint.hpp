#pragma once
#ifdef USE_X11
#include<X.h>
#endif
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<Vector.hpp>
#include<Shader.hpp>
#include<Files.hpp>


namespace swm {
	class Window {
		GLFWwindow* window = nullptr;
		
		public:
		Window(const Window&) = delete;
		void operator=(const Window&) = delete;

		Window(uivec2 windowSize, const char* windowTitle);

		/**
		 * @brief Set the Color the window will be cleared to
		 * 
		 * @param c The color to set the property to
		 */
		void setClearColor(Color c);

		/**
		 * @brief Clear the window to the color selected with setClearColor()
		 * 
		 */
		void clear();

		/**
		 * @brief Checks whether the window close button, or 'Alt + F4' have been pressed
		 * 
		 * @return true if the window should close
		 * @return false otherwise
		 */
		bool shouldClose();
		
		~Window();
	};
}