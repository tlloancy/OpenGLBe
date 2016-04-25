#include <glm/gtc/matrix_transform.hpp>
#include "opgl.h"
void	init_matrix(glm::mat4 *MVP)
{
	// Matrice de projection : Champ de vision de 45° , ration 4:3, distance d'affichage : 0.1 unités <-> 100 unités
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// Matrice de la caméra
	glm::mat4 View       = glm::lookAt(
			glm::vec3(4,3,3), // La caméra est à (4,3,3), dans l'espace monde
			glm::vec3(0,0,0), // et regarde l'origine
			glm::vec3(0,1,0) // La tête est vers le haut (utilisez 0,-1,0 pour regarder à l'envers)
			);
	// Matrice de modèle : une matrice d'identité (le modèle sera à l'origine)
	glm::mat4 Model      = glm::mat4(1.0f); // Changez pour chaque modèle !
	// Notre matrice ModelViewProjection : la multiplication des trois matrices
	*MVP        = Projection * View * Model; // Souvenez-vous, la multiplication de matrice fonctionne dans l'autre sens
	// Obtient la position du sommet, dans l'espace de découpe : MVP * position

}

