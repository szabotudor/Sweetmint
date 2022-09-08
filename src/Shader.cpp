#include<Shader.hpp>
#include<fstream>


namespace swm {
	Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource) {
		if (vertexShaderSource != NULL and fragmentShaderSource != NULL)
			loadShader(vertexShaderSource, fragmentShaderSource);
	}

	void Shader::loadShader(const char* vertexShaderSource, const char* fragmentShaderSource) {
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexShaderSource, NULL);
		glCompileShader(vertex);

		fragment = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(fragment, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragment);
	}

	Shader::~Shader() {

	}
}