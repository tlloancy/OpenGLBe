#ifndef OPGL_H
# define OPGL_H
// Inclure les entêtes standard
#include <stdio.h> 
#include <stdlib.h>
// Inclure GLEW. Toujours l'inclure avant gl.h et glfw.h, car c'est un peu magique. 
#include <GL/glew.h>
// Inclure GLFW 
#include <GLFW/glfw3.h>
// Inclure GLM 
#include <glm/glm.hpp> 
//using namespace glm;
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
void	render_matrix(GLuint programID, glm::mat4 MVP);
void	render_vertex(GLuint programID, GLuint vertexbuffer);
void	init_matrix(glm::mat4 *MVP);
int	init_vertex(GLFWwindow** window, GLuint *vertexbuffer);
#endif
