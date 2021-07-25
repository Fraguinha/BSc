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

GLint WindowWidth = 1200;
GLint WindowHeight = 600;

glm::mat4 mvp;

// Variable definition
const float stp = 0.25f, end = 10.0f;
float x = -10.0f;

const int funSize = (int)((end - x) / stp * 3 + 3);  // sin/cos size

float cx = 0.0f, cy = 0.0f;
float radius = 1.0f;
float theta_s = 0.0f;
const float theta_e = 360.0f;

const int ballSize = (int)((theta_e - theta_s) / stp * 3 + 3);  // circle size

float ystep = 0.15;

//--------------------------------------------------------------------------------
void transferDataToGPUMemory(void) {
  // VAO
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // Create and compile our GLSL program from the shaders
  programID =
      LoadShaders("SimpleVertexShader.glsl", "SimpleFragmentShader.glsl");

  GLfloat g_vertex_buffer_data[funSize * 2 + ballSize];

  // Add cos vertex
  for (int i = 0; i < funSize; i++) {
    g_vertex_buffer_data[i++] = x;
    g_vertex_buffer_data[i++] = cosf(x);
    g_vertex_buffer_data[i] = 0.0f;
    x += stp;
  }

  // Add sin vertex
  x = -10.0f;
  for (int i = funSize; i < 2 * funSize; i++) {
    g_vertex_buffer_data[i++] = x;
    g_vertex_buffer_data[i++] = sinf(x);
    g_vertex_buffer_data[i] = 0.0f;
    x += stp;
  }

  // Add ball vertex
  for (int i = 2 * funSize; i < 2 * funSize + ballSize; i++) {
    g_vertex_buffer_data[i++] = cx + radius * cosf(radians(theta_s));
    g_vertex_buffer_data[i++] = cy + radius * sinf(radians(theta_s));
    g_vertex_buffer_data[i] = 0.0;
    theta_s += stp;
  }

  // Move vertex data to video memory; specifically to VBO called vertexbuffer
  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
               g_vertex_buffer_data, GL_STATIC_DRAW);
}

//--------------------------------------------------------------------------------
void cleanupDataFromGPU() {
  glDeleteBuffers(1, &vertexbuffer);
  glDeleteVertexArrays(1, &VertexArrayID);
  glDeleteProgram(programID);
}

//--------------------------------------------------------------------------------
void draw(int s, int size, float x, float y) {
  // Use our shader
  glUseProgram(programID);

  // retrieve the matrix uniform locations
  unsigned int matrix = glGetUniformLocation(programID, "mvp");
  glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

  glm::mat4 trans;
  trans = glm::translate(glm::mat4(1.0), glm::vec3(x, y, 0.0f));
  unsigned int m = glGetUniformLocation(programID, "trans");
  glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);

  // 1rst attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glDrawArrays(GL_LINE_STRIP, s, size);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

//--------------------------------------------------------------------------------
void drawCos() {
  mvp = glm::ortho(-10.0f, 10.0f, -1.0f, 1.0f);
  draw(0, funSize / 3, 0, 0);
}

//--------------------------------------------------------------------------------
void drawSin() {
  mvp = glm::ortho(-10.0f, 10.0f, -1.0f, 1.0f);
  draw(funSize / 3, funSize / 3, 0, 0);
}

//--------------------------------------------------------------------------------
void drawBall(float y) {
  mvp = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f);
  draw(funSize * 2 / 3, ballSize / 3, 0, y);
}

//--------------------------------------------------------------------------------
int main(void) {
  // Initialise GLFW
  glfwInit();

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
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

  // transfer my data (vertices, colors, and shaders) to GPU side
  transferDataToGPUMemory();

  GLuint FramebufferName = 0;
  glGenFramebuffers(1, &FramebufferName);
  glfwGetFramebufferSize(window, &WindowWidth, &WindowHeight);
  // glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

  // render scene for each frame
  do {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // down left
    glViewport(0, 0, WindowWidth * 0.5, WindowHeight * 0.5);
    drawCos();

    // up left
    glViewport(0, WindowHeight * 0.5, WindowWidth * 0.5, WindowHeight * 0.5);
    drawSin();

    // right
    glViewport(WindowWidth * 0.5, 0, WindowWidth * 0.5, WindowHeight);
    drawBall(cy);

    // BEGIN collision detection for ball

    // reverse direction on top or bottom edge
    if (cy + radius > 10 || cy - radius < -10) {
      ystep = -ystep;
    }

    cy += ystep;  // update y-coordinate for ball origin

    // END collision detection for a square

    // Swap buffers
    glfwSwapBuffers(window);
    // looking for events
    glfwPollEvents();

  }  // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
         glfwWindowShouldClose(window) == 0);

  // delete framebuffer
  glDeleteFramebuffers(1, &FramebufferName);

  // Cleanup VAO, VBOs, and shaders from GPU
  cleanupDataFromGPU();

  // Close OpenGL window and terminate GLFW
  glfwTerminate();

  return 0;
}
