#include <glm/gtc/matrix_transform.hpp>
#include "opgl.h"

void	render_matrix(GLuint programID, glm::mat4 MVP)
{
	// Obtient un identifiant pour notre variable uniforme "MVP".
	// Seulement au moment de l'initialisation.
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Envoie notre transformation au shader actuel dans la variable uniforme "MVP"
	// Pour chaque modèle affiché, comme la MVP sera différente (au moins pour la partie M)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

}

