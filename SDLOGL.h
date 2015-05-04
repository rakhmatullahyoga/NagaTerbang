#ifndef SDLOGL_H_INCLUDED
#define SDLOGL_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <GL/glew.h>
#include "globject.h"
#include "windows.h"

class my_glObject;

class CApp
{
    private:
        bool Running;   //flag to indicate program is running
        SDL_Window* window; //Window
        SDL_GLContext maincontext;  //window context

        my_glObject *myObect;   //openGL object
        my_glObject *nagaBody;
        my_glObject *nagaForeleg;
        my_glObject *nagaHindleg;
        my_glObject *nagaTail;
        my_glObject *nagaWing;
        my_glObject *nagaWing1;
    public:
        CApp();
        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void OnCleanup();
};

#endif // SDLOGL_H_INCLUDED
