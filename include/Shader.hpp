#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cstdint>


namespace swm {
	class Shader {
		uint32_t vertex = 0, fragment = 0;
		
		public:
		Shader(const Shader&) = delete;
		void operator=(const Shader&) = delete;

		/**
		 * @brief Construct a new Shader object (If you wish not to load shader source right away, set both shader sources to NULL)
		 * 
		  * @param vertexShaderSource the source for the vertex shader
		 * @param fragmentShaderSource the source for the fragmentr shader
		 */
		Shader(const char* vertexShaderSource, const char* fragmentShaderSource);

		/**
		 * @brief Compile shader sources and combine them into a shader program
		 * 
		 * @param vertexShaderSource the source for the vertex shader
		 * @param fragmentShaderSource the source for the fragmentr shader
		 */
		void loadShader(const char* vertexShaderSource, const char* fragmentShaderSource);

		/**
		 * @brief Load vertex and fragment shader from files at the given path
		 * 
		 * @param path the path form the shader sources 
		 * @param IMPORTANT(path) (the format for this path is "path/to/shader", which will be converted to "path/to/shader.vert" and "path/to/shader.frag")
		 */
		void loadShaderFile(const char* path);

		~Shader();
	};
}
