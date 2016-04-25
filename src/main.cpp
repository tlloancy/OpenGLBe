#include <glm/gtc/matrix_transform.hpp>
#include "opgl.h"

int	init_window(GLFWwindow** window)
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // antialiasing 4x
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Nous voulons OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Nous ne voulons pas de support de l'ancien OpenGL

	// Ouvre une fenêtre et crée son contexte OpenGL
	*window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
	if( *window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(*window);
	return 0;
}

int main()
{
	glm::mat4 MVP;
	GLFWwindow* window; // (Dans le code joint, cette variable est globale)
	// Ceci identifiera notre tampon de sommets
	GLuint vertexbuffer;

	init_window(&window);
	init_vertex(&window, &vertexbuffer);

	// Crée et compile notre programme GLSL à partir des shaders
	GLuint programID = LoadShaders( "src/SimpleVertexShader.vertexshader", "src/SimpleFragmentShader.fragmentshader" );
	init_matrix(&MVP);
	do{
		// N'affiche rien, à bientôt dans le deuxième tutoriel !
		render_vertex(programID, vertexbuffer);
		render_matrix(programID, MVP);

		// Échange les tampons
		glfwSwapBuffers(window);

	} // Vérifie si la touche échap a été appuyée ou si la fenêtre a été fermée
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
			glfwWindowShouldClose(window) == 0 );
}
