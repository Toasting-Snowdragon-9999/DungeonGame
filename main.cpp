#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {

    SDL_Window* window = SDL_CreateWindow("OpenGL with SDL2 - PNG Viewer",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Load PNG texture


    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        // Adjust the camera
        gluLookAt(0.0, 0.0, 3.0,  // Camera position in World Space
                  0.0, 0.0, 0.0,  // and looks at the origin
                  0.0, 1.0, 0.0); // Head is up

        // Rotate the texture quad
        glRotatef((float)SDL_GetTicks() / 100.0f, 0.0f, 1.0f, 0.0f);

        // Bind the texture and draw a quad
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 0.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 0.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 0.0f);
        glEnd();

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
