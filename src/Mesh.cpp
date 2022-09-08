#include<Mesh.hpp>


namespace swm {
	Mesh::Mesh(DrawMode drawMode) {
	}

	void Mesh::createMeshFromVertexArray(GLfloat* vertices, size_t numVerts) {
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		GLenum gl_DrawMode;
		switch (drawMode) {
		case DrawMode::DYNAMIC:
			gl_DrawMode = GL_DYNAMIC_DRAW;
			break;
		
		case DrawMode::STATIC:
			gl_DrawMode = GL_STATIC_DRAW;
			break;
		
		case DrawMode::STREAM:
			gl_DrawMode = GL_STREAM_DRAW;
			break;
		
		default:
			break;
		};
		glBufferData(GL_ARRAY_BUFFER, numVerts, vertices, gl_DrawMode);
	}
}
