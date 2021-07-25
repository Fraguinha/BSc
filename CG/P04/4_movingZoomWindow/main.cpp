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

// color buffer object (CBO)
GLuint colorbuffer;

// GLSL program from the shaders
GLuint programID;

GLint WindowWidth = 800;  // => 1000
GLint WindowHeight = 800;

// Scene Domain
const GLfloat zoom = 1.02;
GLfloat sceneSize = 60.0;
GLfloat dx = sceneSize * 0.05, dy = sceneSize * 0.05;
GLfloat x = -30.0, y = -30.0;
GLfloat R = sceneSize / sceneSize;

//--------------------------------------------------------------------------------
void transferDataToGPUMemory(void) {
  // VAO
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // Create and compile our GLSL program from the shaders
  programID =
      LoadShaders("SimpleVertexShader.glsl", "SimpleFragmentShader.glsl");

  static GLfloat g_vertex_buffer_data[81] = {
      -3.5f, 3.5f,  0.0f,  // vertices of the roof
      3.5f,  3.5f,  0.0f,  //
      0.0f,  7.0f,  0.0f,  //
      -3.5f, -3.5f, 0.0f,  // vertices of the body
      3.5f,  -3.5f, 0.0f,  //
      -3.5f, 3.5f,  0.0f,  //
      -3.5f, 3.5f,  0.0f,  //
      3.5f,  -3.5f, 0.0f,  //
      3.5f,  3.5f,  0.0f,  //
      -2.5f, 0.5f,  0.0f,  // vertices of left window
      -2.5f, 1.5f,  0.0f,  //
      -1.5f, 0.5f,  0.0f,  //
      -1.5f, 0.5f,  0.0f,  //
      -2.5f, 1.5f,  0.0f,  //
      -1.5f, 1.5f,  0.0f,  //
      1.5f,  0.5f,  0.0f,  // vertices of right window
      1.5f,  1.5f,  0.0f,  //
      2.5f,  0.5f,  0.0f,  //
      2.5f,  0.5f,  0.0f,  //
      1.5f,  1.5f,  0.0f,  //
      2.5f,  1.5f,  0.0f,  //
      -0.5f, -3.5f, 0.0f,  // vertices of the door
      0.5f,  -3.5f, 0.0f,  //
      -0.5f, -0.5f, 0.0f,  //
      0.5f,  -3.5f, 0.0f,  //
      -0.5f, -0.5f, 0.0f,  //
      0.5f,  -0.5f, 0.0f,  //
  };

  static GLfloat g_color_buffer_data[81] = {
      0.0f, 1.0f, 0.0f,  // roof color
      0.0f, 1.0f, 0.0f,  //
      0.0f, 1.0f, 0.0f,  //
      1.0f, 0.0f, 0.0f,  // house color
      1.0f, 0.0f, 0.0f,  //
      1.0f, 0.0f, 0.0f,  //
      1.0f, 0.0f, 0.0f,  //
      1.0f, 0.0f, 0.0f,  //
      1.0f, 0.0f, 0.0f,  //
      0.0f, 0.0f, 1.0f,  // window color
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  // window color
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  //
      0.0f, 0.0f, 1.0f,  //
      0.2f, 0.0f, 0.1f,  // door color
      0.2f, 0.0f, 0.1f,  //
      0.2f, 0.0f, 0.1f,  //
      0.2f, 0.0f, 0.1f,  //
      0.2f, 0.0f, 0.1f,  //
      0.2f, 0.0f, 0.1f,  //
  };

  // Move vertex data to video memory; specifically to VBO called vertexbuffer
  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
               g_vertex_buffer_data, GL_STATIC_DRAW);

  // Move color data to video memory; specifically to CBO called colorbuffer
  glGenBuffers(1, &colorbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data),
               g_color_buffer_data, GL_STATIC_DRAW);
}

//--------------------------------------------------------------------------------
void cleanupDataFromGPU() {
  glDeleteBuffers(1, &vertexbuffer);
  glDeleteBuffers(1, &colorbuffer);
  glDeleteVertexArrays(1, &VertexArrayID);
  glDeleteProgram(programID);
}

//--------------------------------------------------------------------------------
void draw() {
  // Clear the screen
  // glClear(GL_COLOR_BUFFER_BIT);

  // Use our shader
  glUseProgram(programID);

  // create transformations
  glm::mat4 mvp = glm::ortho(x, x + sceneSize, y, y + sceneSize);

  // retrieve the matrix uniform locations
  unsigned int matrix = glGetUniformLocation(programID, "mvp");
  glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

  // 1rst attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glVertexAttribPointer(0,  // attribute 0. No particular reason for 0, but must
                            // match the layout in the shader.
                        3,  // size
                        GL_FLOAT,  // type
                        GL_FALSE,  // normalized?
                        0,         // stride
                        (void*)0   // array buffer offset
  );

  // 2nd attribute buffer : colors
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
  glVertexAttribPointer(1,  // attribute. No particular reason for 1, but must
                            // match the layout in the shader.
                        3,  // size
                        GL_FLOAT,  // type
                        GL_FALSE,  // normalized?
                        0,         // stride
                        (void*)0   // array buffer offset
  );

  glDrawArrays(GL_TRIANGLES, 0, 27);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}
//--------------------------------------------------------------------------------
void handleKeyboardInput() {
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
    x -= dx;
  }
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
    y -= dy;
  }
  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
    y += dy;
  }
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    x += dx;
  }
  if (glfwGetKey(window, GLFW_KEY_SLASH) == GLFW_PRESS) {
    // US / => PT -
    x *= zoom;
    y *= zoom;
    dx *= zoom;
    dy *= zoom;
    sceneSize *= zoom;
  }
  if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS) {
    // US = => PT +
    x /= zoom;
    y /= zoom;
    dx /= zoom;
    dy /= zoom;
    sceneSize /= zoom;
  }
  if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
    x -= dx;
  }
  if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
    y -= dy;
  }
  if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
    y += dy;
  }
  if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
    x += dx;
  }
}
//--------------------------------------------------------------------------------
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
  window =
      glfwCreateWindow(WindowWidth, WindowHeight, "Moving Window", NULL, NULL);

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

  glfwGetFramebufferSize(window, &WindowWidth, &WindowHeight);

  // render scene for each frame
  do {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, WindowWidth, WindowWidth / R);
    draw();

    // Swap buffers
    glfwSwapBuffers(window);

    // looking for events
    glfwPollEvents();

    handleKeyboardInput();

  }  // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
         glfwWindowShouldClose(window) == 0);

  // Cleanup VAO, VBOs, and shaders from GPU
  cleanupDataFromGPU();

  // Close OpenGL window and terminate GLFW
  glfwTerminate();

  return 0;
}
