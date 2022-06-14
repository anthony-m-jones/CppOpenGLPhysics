#define _USE_MATH_DEFINES

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <../Source/Helpers/ShaderUtil.h>
#include <vector>
#include <../Source/Helpers/Vector2.h>
#include <../Source/Helpers/Particle2.h>
#include <math.h>
#include <cmath>

MyCppOpenGLProject::Particle2 ball{ 0,0,0,0,0 };
MyCppOpenGLProject::Vector2 acceleration{ 0,0 };

const float accel = 0.001f;

bool upPressed = false;
bool downPressed = false;
bool leftPressed = false;
bool rightPressed = false;

static void DrawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Set up pressed
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        acceleration.SetY(accel);
    if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
        acceleration.SetY(0);

    // Set down pressed
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        acceleration.SetY(-accel);
    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
        acceleration.SetY(0);

    // Set left pressed
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        acceleration.SetX(-accel);
    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
        acceleration.SetX(0);

    // Set right pressed
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        acceleration.SetX(accel);
    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
        acceleration.SetX(0);
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err) {
        /*Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    glfwSetKeyCallback(window, key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Render ball
        ball.Accelerate(acceleration);
        ball.Update();
        DrawCircle(ball.position.GetX(), ball.position.GetY(), 0.01f, 20);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    //shaderUtil.Delete();

    glfwTerminate();
    return 0;
}