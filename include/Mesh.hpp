#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<cstdint>


namespace swm {
	class Mesh {
		public:
		/**
		 * @brief Specify how the data will be processed by the GPU
		 * 
		 * @param STREAM the data is set only once and used by the GPU at most a few times
		 * @param STATIC the data is set only once and used many times
		 * @param DYNAMIC the data is changed a lot and used many times
		 * 
		 */
		enum class DrawMode {
			STREAM,
			STATIC,
			DYNAMIC
		};

		private:
		DrawMode drawMode{};
		uint32_t VBO;
		
		public:
		Mesh(const Mesh&) = delete;
		void operator=(const Mesh&) = delete;

		Mesh(DrawMode drawMode = DrawMode::STATIC);

		void createMeshFromVertexArray(GLfloat* vertices, size_t numVerts);

		~Mesh();
	};
}
