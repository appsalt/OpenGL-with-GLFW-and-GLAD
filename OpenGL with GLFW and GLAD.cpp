// OpenGL with GLFW and GLAD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    std::cout << "OpenGL project START\n";

    /* We will use Graphics Library Framework (GLFW) functions to create a window
    *
    * GLFW is an Open Source, multi-platform library for OpenGL
    *
    * To use glfw functions; GLFW needs to be initialized
    * (specifics are unknow to me at this point).
    *
    * There is also a termination function for GLFW that should be used at the end of the scope
    * (specifics are unknow to me at this point, probably destructors and deleations).
    *
    * We use the GLFW initialization function ( glfwInit() ) to initialize glfw.
    */
    glfwInit();

    // This part is very uncelear; however,
    // we give a "hint" to GLFW window that we are going to use the major and minor version of OpenGL 3...
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // we give a "hint" to GLFW window that we are going to use OpenGL with the core profile 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Now lets create the window! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    // We make a pointer to a GLFWwindow object, called Window_1; 
    // and put a GLFWwindow object there, using the GLFWwindow object creation function 
    // glfwCreateWindow(resolution, resoulution, name, fullscreen, unknown)    
    GLFWwindow* Window_1;
    Window_1 = glfwCreateWindow(800, 800, "Window_1", NULL, NULL);
    // GLFWwindow* Window_1 = glfwCreateWindow(800,800,"Window_1",NULL,NULL); // also work

    // This is just a fail case, its not needed
    if (Window_1 == NULL)
    {
        std::cout << "(GLFWwindow*) Window_1 == NULL\n";
        glfwTerminate();
        return -1;
    }


    // We need to also make the created window part of the current context, even OpenGL is in the GLFW context  
    // (specifics are unknow to me at this point) 
    glfwMakeContextCurrent(Window_1);

    // The function glfwWindowShouldClose(GLFWwindow* "name") checks if the GLFWwindow object is suposed suposed to close
    // the the object probably stores some varible that changes depending on events that has occured
    // such as if the x button of the window has ben pressed

    // Now we need to make the window do work and run! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 

    // We are using GLAD to create the screen buffers for OpenGL that will be in the GLFWwindow 
    // We need to use the GLADs load function to start using GLAD
        gladLoadGL();

    // We need to specifiy how big the GLAD OpenGL screen buffer should be 
    // We use the GLAD function glViewport(beginX, beginY, endX, endY) 
    // and give the same dimentions as the windows starting dimentions
        glViewport(0, 0, 800, 800);

    /* Screen Buffer info 
    * 
    * There are 2 buffers; the fron buffer and tha back buffer
    * The fron buffer is shown on screen and the back buffer is not 
    * We cannot operate on the front buffer, but we can operate on the back buffer
    * When we have made changes we want to the back buffer, we can then swap it with the fron buffer
    * When the buffers have been swaped; 
    * the former front buffer becomes the current back buffer and the former back buffer is now the fron buffer in the window.
    */

    // We want to change the color on screen 
    // We do this by changing GL_COLOR_BUFFER_BIT color with glClearColor(r, g, b, alpha)
        glClearColor(0.60f, 0.60f, 1.00f, 1.00f);

    // We change the color of the back buffer with glClear("input")
        glClear(GL_COLOR_BUFFER_BIT);

    // Now we also need to swap the front and back buffers of the GLFWwindow
        glfwSwapBuffers(Window_1);
    

    /* 
    * We create a while loop
    * with the function that checks if the GLFWwindow should close
    * as the condition (while it should NOT close)
    *
    * Each while loop cycle we check/update what has hapened to the window
    * with the function glfwPollEvents()
    * if we do not do this the window will not be interactable
    */
        while (!glfwWindowShouldClose(Window_1))
        {
            glfwPollEvents();
        }




    // Even thoug the program ends here; 
    // for good habit, 
    // we destroy the GLFWwindow objects
    glfwDestroyWindow(Window_1);
    // we use the GLFW termination function because we no longer need to use GLFW
    glfwTerminate();

    std::cout << "OpenGL project END\n";
    return 0;
}
