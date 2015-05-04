#include "SDLOGL.h"
void CApp::OnRender() {
    /* Clear our buffer with a red background */
    //glClearColor ( 1.0, 0.0, 0.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );
    /* Swap our back buffer to the front */
    myObect->display();
    nagaBody->display();
    nagaForeleg->display();
    nagaHindleg->display();
    nagaTail->display();
    nagaWing->display();
    SDL_GL_SwapWindow(window);
    Sleep(200);
    myObect->display();
    nagaBody->display();
    nagaForeleg->display();
    nagaHindleg->display();
    nagaTail->display();
    nagaWing1->display();
    SDL_GL_SwapWindow(window);
    Sleep(200);
}
