#ifndef GKOBJECT_H_INCLUDED
#define GKOBJECT_H_INCLUDED
#include <stdio.h>
#include <string>
#include <vector>
//#include <gl/glew.h>
#include "SDLOGL.h"
using namespace std;
class CApp;


class my_glObject
{
protected:
    GLuint VertexArrayID;
    GLuint programID;
    GLfloat vertexBufferData[64];
    GLfloat vertexBufferColor[64];
    GLfloat vertexBufferColorBlack[64];
    GLfloat red;
    GLfloat green;
    GLfloat blue;
    GLuint vertexbuffer;
    GLuint vertexcolor;
    vector<float> NTitik;

public:
    bool init(string filename);
    void setWarna(GLfloat R, GLfloat G, GLfloat B);
    bool LoadShaders(string vs,string fs);
    GLuint getVertexArrayID(){return VertexArrayID;}
    GLuint getprogramID(){return programID;}
    bool display();
    void cleanup();
    void hapus();
    void draw();
};

#endif // GKOBJECT_H_INCLUDED
