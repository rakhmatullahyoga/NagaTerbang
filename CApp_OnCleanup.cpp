#include "SDLOGL.h"

void CApp::OnCleanup() {
    myObect->cleanup();
    nagaBody->cleanup();
    nagaForeleg->cleanup();
    nagaHindleg->cleanup();
    nagaTail->cleanup();
    nagaWing->cleanup();
    SDL_GL_DeleteContext(maincontext);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
