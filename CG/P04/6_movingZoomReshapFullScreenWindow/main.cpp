// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;
const GLFWvidmode* mode;

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

GLint WindowWidth = 800;      // Windowed mode's width
GLint WindowHeight = 800;     // Windowed mode's height
GLint windowPosX = 50;        // Windowed mode's top-left corner x
GLint windowPosY = 50;        // Windowed mode's top-left corner y
bool fullScreenMode = false;  // Full-screen or windowed mode?

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
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  // 2nd attribute buffer : colors
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glDrawArrays(GL_TRIANGLES, 0, 27);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

//--------------------------------------------------------------------------------
void handleKeyboardInput(GLFWwindow* window, int key, int scancode, int action,
                         int mods) {
  if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
    x -= dx;
  }
  if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
    y -= dy;
  }
  if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
    y += dy;
  }
  if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
    x += dx;
  }
  if (key == GLFW_KEY_SLASH && action == GLFW_PRESS) {
    // US / => PT -
    x *= zoom;
    y *= zoom;
    dx *= zoom;
    dy *= zoom;
    sceneSize *= zoom;
  }
  if (key == GLFW_KEY_EQUAL && action == GLFW_PRESS) {
    // US = => PT +
    x /= zoom;
    y /= zoom;
    dx /= zoom;
    dy /= zoom;
    sceneSize /= zoom;
  }
  if (key == GLFW_KEY_H && action == GLFW_PRESS) {
    WindowWidth -= WindowWidth * 0.05;
    glfwSetWindowSize(window, WindowWidth, WindowHeight);
  }
  if (key == GLFW_KEY_J && action == GLFW_PRESS) {
    WindowHeight += WindowWidth * 0.05;
    glfwSetWindowSize(window, WindowWidth, WindowHeight);
  }
  if (key == GLFW_KEY_K && action == GLFW_PRESS) {
    WindowHeight -= WindowWidth * 0.05;
    glfwSetWindowSize(window, WindowWidth, WindowHeight);
  }
  if (key == GLFW_KEY_L && action == GLFW_PRESS) {
    WindowWidth += WindowWidth * 0.05;
    glfwSetWindowSize(window, WindowWidth, WindowHeight);
  }
  if ((key == GLFW_KEY_F1 && action == GLFW_PRESS)) {
    fullScreenMode = !fullScreenMode;
    if (fullScreenMode) {
      glfwGetWindowPos(window, &windowPosX, &windowPosY);
      glfwGetWindowSize(window, &WindowWidth, &WindowHeight);

      glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width,
                           mode->height, mode->refreshRate);
    } else {
      glfwSetWindowMonitor(window, NULL, windowPosX, windowPosY, WindowWidth,
                           WindowHeight, 0);
    }
  }
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
  window =
      glfwCreateWindow(WindowWidth, WindowHeight, "Moving Window", NULL, NULL);

  // Get mode for full screen functionality
  mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
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

  // Retina displays workaround
  int w, h;
  glfwGetFramebufferSize(window, &w, &h);
  int r = w / WindowWidth;

  // render scene for each frame
  do {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    if (fullScreenMode) {
      glViewport(0, 0, mode->width * r, mode->width * r / R);
    } else {
      glViewport(0, 0, w, w / R);
    }
    draw();

    // Swap buffers
    glfwSwapBuffers(window);

    // looking for events
    glfwPollEvents();

    // setKeyCallback
    glfwSetKeyCallback(window, handleKeyboardInput);

  }  // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
         glfwWindowShouldClose(window) == 0);

  // Cleanup VAO, VBOs, and shaders from GPU
  cleanupDataFromGPU();

  // Close OpenGL window and terminate GLFW
  glfwTerminate();

  return 0;
}
