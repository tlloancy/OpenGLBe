#include <glm/gtc/matrix_transform.hpp>
#include "opgl.h"
void	render_vertex(GLuint programID, GLuint vertexbuffer)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Utilise notre shader
	glUseProgram(programID);

	// Dessine le triangle...
	// premier tampon d'attributs : les sommets
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
			0,                  // attribut 0. Aucune raison particulière pour 0, mais cela doit correspondre au « layout » dans le shader
			3,                  // taille
			GL_FLOAT,           // type
			GL_FALSE,           // normalisé ?
			0,                  // nombre d'octets séparant deux sommets dans le tampon
			(void*)0            // décalage du tableau de tampon
			);

	// Dessine le triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Démarre à partir du sommet 0; 3 sommets au total -> 1 triangle

	glDisableVertexAttribArray(0);
}

