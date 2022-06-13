#define _USE_MATH_DEFINES

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <../Source/ShaderUtil.h>
#include <vector>
#include <../Source/Vector2.h>
#include <math.h>
#include <cmath>

std::vector<float> ballVelocity = { 0, 0, 0 };
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
        upPressed = true;
    if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
        upPressed = false;

    // Set down pressed
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        downPressed = true;
    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
        downPressed = false;

    // Set left pressed
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        leftPressed = true;
    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
        leftPressed = false;

    // Set right pressed
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        rightPressed = true;
    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
        rightPressed = false;
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

    float ballPosX = 0, ballPosY = 0;
    float accelleration = 0.0001f;
    glfwSetKeyCallback(window, key_callback);

    MyCppOpenGLProject::Vector2 v1{ 10,5 }, v2{ 3,4 }, v3 = v1 + v2;
    std::cout << "My Vector2 Angle: " + std::to_string(v3.GetAngle()) << std::endl;
    std::cout << "My Vector2 Length: " + std::to_string(v3.GetLength()) << std::endl;
    std::cout << "My Vector2 X: " + std::to_string(v3.GetX()) << std::endl;
    std::cout << "My Vector2 Y: " + std::to_string(v3.GetY()) << std::endl;

    v3 = v3 * 2;
    std::cout << "My Vector2 Angle: " + std::to_string(v3.GetAngle()) << std::endl;
    std::cout << "My Vector2 Length: " + std::to_string(v3.GetLength()) << std::endl;
    std::cout << "My Vector2 X: " + std::to_string(v3.GetX()) << std::endl;
    std::cout << "My Vector2 Y: " + std::to_string(v3.GetY()) << std::endl;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Update physics
        if (downPressed)
            ballVelocity[1] -= accelleration;
        else if (upPressed) ballVelocity[1] += accelleration;

        if (leftPressed)
            ballVelocity[0] -= accelleration;
        else if (rightPressed)
            ballVelocity[0] += accelleration;


        ballPosX += ballVelocity[0];
        ballPosY += ballVelocity[1];

        // Render ball
        DrawCircle(ballPosX, ballPosY, 0.1f, 45);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    //shaderUtil.Delete();

    glfwTerminate();
    return 0;
}