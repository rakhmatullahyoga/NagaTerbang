#include "SDLOGL.h"

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    //win = SDL_CreateWindow("Image Loading", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
     if((window = SDL_CreateWindow("Naga Terbang",100,100,640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN)) == NULL) {
        return false;
    }
    maincontext = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1);
    glewExperimental=true;
    GLenum err=glewInit();
    myObect = new my_glObject;
    myObect->setWarna(1.0,0.0,0.0);
    myObect->init("naga_head.txt");
    nagaBody = new my_glObject;
    nagaBody->setWarna(0.0,1.0,0.0);
    nagaBody->init("naga_body.txt");
    nagaForeleg = new my_glObject;
    nagaForeleg->setWarna(0.0,0.0,1.0);
    nagaForeleg->init("naga_foreleg.txt");
    nagaHindleg = new my_glObject;
    nagaHindleg->setWarna(0.0,0.0,1.0);
    nagaHindleg->init("naga_hindleg.txt");
    nagaTail = new my_glObject;
    nagaTail->setWarna(1.0,0.0,0.0);
    nagaTail->init("naga_tail.txt");
    nagaWing = new my_glObject;
    nagaWing->setWarna(0.0,1.0,1.0);
    nagaWing->init("naga_wing.txt");
    nagaWing1 = new my_glObject;
    nagaWing1->setWarna(0.0,1.0,1.0);
    nagaWing1->init("naga_wing1.txt");
    return true;
}
