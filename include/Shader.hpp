#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cstdint>


namespace swm {
	class Shader {
		public:
		Shader(const Shader&) = delete;
		void operator=(const Shader&) = delete;

		Shader();

		/**
		 * @brief Load shader files, compile them, and bind them to a program
		 * 
		 * @param vertexShaderFile The file for the vertex shader source code
		 * @param fragmentShaderFile The file for the fragment shader source code
		 */
		void loadShader(const char* vertexShaderFile, const char* fragmentShaderFile);

		~Shader();
	};
}
