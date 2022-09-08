#include<Mesh.hpp>


namespace swm {
	Mesh::Mesh(DrawMode drawMode) {
		Mesh::drawMode = drawMode;
	}

	void Mesh::createMeshFromVertexArray(GLfloat* vertices, size_t numVerts) {
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, numVerts, vertices, GL_DRAW_MODE_LIST[(uint32_t)drawMode]);
	}
}
