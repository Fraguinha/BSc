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

GLint WindowWidth = 800;
GLint WindowHeight = 800;

// Toggle Flags
static bool showRoof = true;
static bool showBody = true;
static bool showWindow = true;
static bool showDoor = true;

float delta = 0.0;
GLfloat theta = 0.0;

GLint sunSize;

//--------------------------------------------------------------------------------
void transferDataToGPUMemory(void) {
  // VAO
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // Create and compile our GLSL program from the shaders
  programID =
      LoadShaders("SimpleVertexShader.glsl", "SimpleFragmentShader.glsl");

  static GLfloat g_vertex_buffer_data[24081] = {
      0.0f, 0.0f, 0.0f,  // vertices of the roof
      3.5f, 3.5f, 0.0f,  //
      7.0f, 0.0f, 0.0f,  //
      0.0f, 0.0f, 0.0f,  // vertices of the body
      7.0f, 0.0f, 0.0f,  //
      0.0f, 7.0f, 0.0f,  //
      0.0f, 7.0f, 0.0f,  //
      7.0f, 0.0f, 0.0f,  //
      7.0f, 7.0f, 0.0f,  //
      0.0f, 1.0f, 0.0f,  // vertices of window
      1.0f, 0.0f, 0.0f,  //
      0.0f, 0.0f, 0.0f,  //
      0.0f, 1.0f, 0.0f,  //
      1.0f, 0.0f, 0.0f,  //
      1.0f, 1.0f, 0.0f,  //
      0.0f, 0.0f, 0.0f,  // vertices of the door
      0.0f, 3.0f, 0.0f,  //
      1.0f, 0.0f, 0.0f,  //
      1.0f, 0.0f, 0.0f,  //
      0.0f, 3.0f, 0.0f,  //
      1.0f, 3.0f, 0.0f,  //
  };

  static GLfloat g_color_buffer_data[24081] = {
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
      0.2f, 0.0f, 0.1f,  // door color
      0.2f, 0.0f, 0.1f,  //
      0.2f, 0.0f, 0.1f,  //
      0.2f, 0.0f, 0.1f,  //
      0.2f, 0.0f, 0.1f,  //
      0.2f, 0.0f, 0.1f,  //
  };

  // Variable definition
  float step = 0.045f;
  float cx = 0.0f, cy = 0.0f;
  float radius = 2.0f;
  float theta_s = 0.0f;
  float theta_e = 360.0f;
  sunSize = (int)((theta_e - theta_s) / step) * 3;

  for (int i = 63; i < sunSize + 63; i++) {
    g_color_buffer_data[i] = 1.0;
    g_vertex_buffer_data[i++] = cx + radius * cosf(theta_s);
    g_color_buffer_data[i] = 2.0;
    g_vertex_buffer_data[i++] = cy + radius * sinf(theta_s);
    g_color_buffer_data[i] = 0.0;
    g_vertex_buffer_data[i] = 0.0;
    theta_s += step;
  }

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
void draw(GLint start, GLint size, GLfloat dx, GLfloat dy, GLfloat scale,
          GLenum mode, GLfloat theta) {
  // Clear the screen
  // glClear(GL_COLOR_BUFFER_BIT);

  // Use our shader
  glUseProgram(programID);

  // create transformations
  // glm::mat4 model = glm::mat4(1.0f);
  // glm::mat4 view = glm::mat4(1.0f);
  glm::mat4 mvp = glm::ortho(-30.0f, 30.0f, -30.0f, 30.0f);

  // Our ModelViewProjection : multiplication of our 3 matrices
  // glm::mat4 mvp = projection * view * model;
  // Remember, matrix multiplication is the other way around

  // retrieve the matrix uniform locations
  unsigned int matrix = glGetUniformLocation(programID, "mvp");
  glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

  glm::mat4 trans;
  trans =
      glm::translate(glm::mat4(1.0), glm::vec3(delta + dx, delta + dy, 0.0f));
  unsigned int m1 = glGetUniformLocation(programID, "trans");
  glUniformMatrix4fv(m1, 1, GL_FALSE, &trans[0][0]);

  glm::mat4 scal;
  scal = glm::scale(glm::mat4(1.0), glm::vec3(scale, scale, 0.0f));
  unsigned int m2 = glGetUniformLocation(programID, "scal");
  glUniformMatrix4fv(m2, 1, GL_FALSE, &scal[0][0]);

  glm::vec3 myRotationAxis(0.0f, 0.0f, 1.0f);
  glm::mat4 rot =
      glm::rotate(glm::mat4(1.0), glm::radians(theta), myRotationAxis);
  unsigned int m3 = glGetUniformLocation(programID, "rot");
  glUniformMatrix4fv(m3, 1, GL_FALSE, &rot[0][0]);

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

  glDrawArrays(mode, start, size);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}
//--------------------------------------------------------------------------------
void drawRoof(GLfloat dx, GLfloat dy, GLfloat scale) {
  if (glfwGetKey(window, GLFW_KEY_R) != glfwGetKey(window, GLFW_KEY_R)) {
    showRoof = !showRoof;
  }

  if (showRoof) {
    draw(0, 3, dx, dy, scale, GL_TRIANGLES, 0);
  }
}
//--------------------------------------------------------------------------------
void drawBody(GLfloat dx, GLfloat dy, GLfloat scale) {
  if (glfwGetKey(window, GLFW_KEY_B) != glfwGetKey(window, GLFW_KEY_B)) {
    showBody = !showBody;
  }

  if (showBody) {
    draw(3, 6, dx, dy, scale, GL_TRIANGLES, 0);
  }
}
//--------------------------------------------------------------------------------
void drawWindow(GLfloat dx, GLfloat dy, GLfloat scale) {
  if (glfwGetKey(window, GLFW_KEY_W) != glfwGetKey(window, GLFW_KEY_W)) {
    showWindow = !showWindow;
  }

  if (showWindow) {
    draw(9, 6, dx, dy, scale, GL_TRIANGLES, 0);
  }
}
//--------------------------------------------------------------------------------
void drawDoor(GLfloat dx, GLfloat dy, GLfloat scale) {
  if (glfwGetKey(window, GLFW_KEY_D) != glfwGetKey(window, GLFW_KEY_D)) {
    showDoor = !showDoor;
  }

  if (showDoor) {
    draw(15, 6, dx, dy, scale, GL_TRIANGLES, 0);
  }
}
//--------------------------------------------------------------------------------
void drawSun(GLfloat dx, GLfloat dy) {
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    theta += 1;
  }

  draw(21, sunSize / 3, dx, dy, 1, GL_TRIANGLE_FAN, theta);
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
  window = glfwCreateWindow(WindowWidth, WindowHeight, "Moving House in 2D ",
                            NULL, NULL);

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

  // render scene for each frame
  do {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // drawing house (3/4)
    GLfloat scale = 3.0f / 4.0f;

    drawRoof(-8.75f, 1.75f, scale);
    drawBody(-8.75f, -3.5f, scale);
    drawWindow(-5.0f, -0.5f, scale);
    drawWindow(-8.0f, -0.5f, scale);
    drawDoor(-6.5f, -3.5f, scale);

    scale = 1;
    // drawing house
    drawRoof(-3.5f, 3.5f, scale);
    drawBody(-3.5f, -3.5f, scale);
    drawWindow(-2.5f, 0.5f, scale);
    drawWindow(1.5f, 0.5f, scale);
    drawDoor(-0.5f, -3.5f, scale);

    scale = 5.0f / 4.0f;
    // drawing house (5/4)
    drawRoof(3.5f, 5.25f, scale);
    drawBody(3.5f, -3.5f, scale);
    drawWindow(4.75f, 2.0f, scale);
    drawWindow(9.75f, 2.0f, scale);
    drawDoor(7.25f, -3.5f, scale);

    drawSun(15, 6);
    // Swap buffers
    glfwSwapBuffers(window);

    // looking for events
    glfwPollEvents();

    if (delta < 10) delta += 0.1;

  }  // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
         glfwWindowShouldClose(window) == 0);

  // Cleanup VAO, VBOs, and shaders from GPU
  cleanupDataFromGPU();

  // Close OpenGL window and terminate GLFW
  glfwTerminate();

  return 0;
}
