// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

// shaders header file
#include "shader.h"

// Vertex array object (VAO)
GLuint VertexArrayID;

// Vertex buffer object (VBO)
GLuint vertexbuffer;

// GLSL program from the shaders
GLuint programID;

GLint WindowWidth = 600;
GLint WindowHeight = 600;

// Used variables
const float stp = 0.25f;  // Quanto variar o 'x' por iteração
const float end = 10.0f;  // Ultimo 'x' a ser calculado
float x = -10.0f;         // O 'x' em sin(x) ou cos(x)

// Number of points to draw per function
const int size = (int)((end - x) / stp * 3 + 3);  // Numero de pontos

//------------------------------------------------------------------------------
/**
 *  Nesta função são transferidos para a GPU um array que contem todos os pontos
 *  que terão que ser desenhados durante a execução do programa
 *
 *                  (CPU)                            (GPU)
 *           g_vertex_buffer_data                vertexbuffer
 *             +-------------+                  +-------------+
 *             |  0   | cos  |                  |  0   | cos  |
 *             +-------------+                  +-------------+
 *             | ...  | ...  |                  | ...  | ...  |
 *             +-------------+        -->       +-------------+
 *             | size | sin  |                  | size | sin  |
 *             +-------------+                  +-------------+
 *             | ...  | ...  |                  | ...  | ...  |
 *             +-------------+                  +-------------+
 *
 */
void transferDataToGPUMemory(void) {
  // VAO
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // Create and compile our GLSL program from the shaders
  programID =
      LoadShaders("SimpleVertexShader.glsl", "SimpleFragmentShader.glsl");

  GLfloat g_vertex_buffer_data[size * 2];

  /**
   *  O 1º ponto corresponde ao x -> x
   *  O 2º ponto corresponde ao y -> cos(x)
   *  O 3º ponto corresponde ao z -> 0 (Representação 2D)
   */
  for (int i = 0; i < size; i++) {
    g_vertex_buffer_data[i++] = x;
    g_vertex_buffer_data[i++] = cosf(x);
    g_vertex_buffer_data[i] = 0.0f;
    x += stp;
  }

  /**
   *  O 1º ponto corresponde ao x -> x
   *  O 2º ponto corresponde ao y -> sin(x)
   *  O 3º ponto corresponde ao z -> 0 (Representação 2D)
   */
  x = -10.0f;
  for (int i = size; i < 2 * size; i++) {
    g_vertex_buffer_data[i++] = x;
    g_vertex_buffer_data[i++] = sinf(x);
    g_vertex_buffer_data[i] = 0.0f;
    x += stp;
  }

  // Move vertex data to video memory; specifically to VBO called vertexbuffer
  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
               g_vertex_buffer_data, GL_STATIC_DRAW);
}

//------------------------------------------------------------------------------
void cleanupDataFromGPU() {
  glDeleteBuffers(1, &vertexbuffer);
  glDeleteVertexArrays(1, &VertexArrayID);
  glDeleteProgram(programID);
}

//------------------------------------------------------------------------------
/**
 *  A função draw recebe um parametro com o indice onde começar a desenhar os
 *  pontos do array e desenha (size / 3) pontos
 */
void draw(int s) {
  // Use our shader
  glUseProgram(programID);

  // create transformations
  glm::mat4 mvp = glm::ortho(-10.0f, 10.0f, -1.0f, 1.0f);

  // retrieve the matrix uniform locations
  unsigned int matrix = glGetUniformLocation(programID, "mvp");
  glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

  // 1rst attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glDrawArrays(GL_LINE_STRIP, s, size / 3);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

//------------------------------------------------------------------------------
/**
 *  Para desenhar a função cosseno será necessário chamar a função draw(), neste
 *  caso os pontos que correspondem a função cosseno começam no indice 0
 */
void drawCos() { draw(0); }

//------------------------------------------------------------------------------
/**
 *  De igual forma, para desenhar a função seno, temos que chamar a função
 *  draw() no indice (size / 3)
 */
void drawSin() { draw(size / 3); }

//------------------------------------------------------------------------------
int main(void) {
  // Initialise GLFW
  glfwInit();

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,
                 GL_TRUE);  // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Open a window
  window = glfwCreateWindow(WindowWidth, WindowHeight,
                            "Sin e Cos in 2 Viewports", NULL, NULL);

  // Create window context
  glfwMakeContextCurrent(window);

  // Initialize GLEW
  glewExperimental = true;  // Needed for core profile
  glewInit();

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  // White background
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

  // Clear the screen
  glClear(GL_COLOR_BUFFER_BIT);

  // transfer my data (vertices, colors, and shaders) to GPU side
  transferDataToGPUMemory();

  GLuint FramebufferName = 0;
  glGenFramebuffers(1, &FramebufferName);
  // glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

  /**
   *  Nos MacOS com displays retina, é normalmente utilizado um scale de 2.0 por
   *  omição, o que faz com que seja preciso desenhar o dobro dos pixeis
   *
   *  Esta função permite obter o numero real de pixeis da janela
   */
  glfwGetFramebufferSize(window, &WindowWidth, &WindowHeight);

  // render scene for each frame
  do {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    /**
     *  Criar um viewport para a parte inferior da janela que contem a curva
     *  da função cosseno. Esta viewport começa  em (0, 0) ou seja o canto
     *  inferior esquerdo da janela, tem a largura total e metade da altura da
     *  janela.
     */
    glViewport(0, 0, WindowWidth, WindowHeight * 0.5);
    drawCos();

    /**
     *  Criar um viewport para a parte superior da janela que contem
     *  a curva da função seno. Esta viewport começa em (0, WindowHeight/2)
     *  ou seja a esquerda e a metade da altura da janela, tem a largura total
     *  e metade da altura da janela.
     */
    glViewport(0, WindowHeight * 0.5, WindowWidth, WindowHeight * 0.5);
    drawSin();

    // Swap buffers
    glfwSwapBuffers(window);

    // looking for events
    glfwPollEvents();

  } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0);

  // delete framebuffer
  glDeleteFramebuffers(1, &FramebufferName);

  // Cleanup VAO, VBOs, and shaders from GPU
  cleanupDataFromGPU();

  // Close OpenGL window and terminate GLFW
  glfwTerminate();

  return 0;
}
