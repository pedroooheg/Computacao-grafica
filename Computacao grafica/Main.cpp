#include <stdio.h>
#include <GL/glew.h>	
#include <GLFW\glfw3.h>

const GLint width = 800, height = 600;	

int main() {

	// Iniciar o GLFW

	if (!glfwInit()) {
		printf("Falha ao inicializar o GLFW\n");
		glfwTerminate();
		return 1;


	}
	// Criar uma janela
	// defindo em qual versao do opengl ira rodar
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// defindo o perfil do opengl 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS
		// tamanho da tela / nome da janela / 
	GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
	if (!window) {
		printf("Falha ao criar a janela\n");
		glfwTerminate();
		return 1;
	}

	// duas variaveis para gaurdar o buffer da janela, passa op endereco pois pede um ponteiro 

	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
	//principal janela
	glfwMakeContextCurrent(window);


	glewExperimental = GL_TRUE; // habilita o uso de extensoes do glew
	if (glewInit() != GLEW_OK) {
		printf("Falha ao inicializar o GLEW\n");
		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}

	glViewport(0, 0, bufferWidth, bufferHeight); // define a area de visualizacao da janela

	// Loop principal fica verificando se  janela precisa ser fechada
	while (!glfwWindowShouldClose(window)) {
		// define a cor de fundo da janela
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
		glfwPollEvents(); // verifica eventos da janela
		glClear(GL_COLOR_BUFFER_BIT); // limpa a janela com a cor definida
		glfwSwapBuffers(window); // troca os buffers da janela, para que a cor de fundo apareça
	
	}
	glfwDestroyWindow(window); // destrói a janela criada)
	glfwTerminate(); // encerra o GLFW
	return 0; // retorna 0 para indicar que o programa terminou com sucesso


}

