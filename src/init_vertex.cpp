#include <glm/gtc/matrix_transform.hpp>
#include "opgl.h"
int	init_vertex(GLFWwindow** window, GLuint *vertexbuffer)
{

	// Un tableau de trois vecteurs qui représentent trois sommets
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};
	// Initialise GLEW
	glewExperimental=true; // Nécessaire pour le profil core
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	// S'assure que l'on puisse capturer la touche échap utilisée plus bas
	glfwSetInputMode(*window, GLFW_STICKY_KEYS, GL_TRUE);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Génère un tampon et place l'identifiant dans 'vertexbuffer'
	glGenBuffers(1, vertexbuffer);

	// Les commandes suivantes vont parler de notre tampon 'vertexbuffer'
	glBindBuffer(GL_ARRAY_BUFFER, *vertexbuffer);

	// Fournit les sommets à OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	return 0;

}

