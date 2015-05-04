#include"globject.h"
#include <fstream>
#include <iostream>

void my_glObject::setWarna(GLfloat R, GLfloat G, GLfloat B)
{
    red = R;
    green = G;
    blue = B;
}
void my_glObject::hapus(){
    glBindBuffer(GL_ARRAY_BUFFER,vertexcolor);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexBufferColorBlack),vertexBufferColorBlack,GL_STATIC_DRAW);
}
void my_glObject::draw(){
    glBindBuffer(GL_ARRAY_BUFFER,vertexcolor);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexBufferColor),vertexBufferColor,GL_STATIC_DRAW);
}

bool my_glObject::init(string filename)
{
    //LoadShaders("2nd.vs","fragmentshader.fs");
    glGenVertexArrays(1,&VertexArrayID);
    glBindVertexArray(VertexArrayID);

    //from file extern
    float a,b;
    float c = 0.0;
    string dir = filename;
    string line;
    ifstream myfile (dir.c_str());
  	if (myfile.is_open()){
    	while ( getline (myfile,line) ){
      		a = atof(line.substr (0,line.find(",")).c_str());
      		b = atof(line.substr (line.find(",")+1).c_str());
      		a+=-0.5;
      		b+=0.5;
      		NTitik.push_back(a);
      		NTitik.push_back(b);
      		NTitik.push_back(c);
    	}
    	myfile.close();
  	}
  	/*for(int i=0;i<NTitik.size();i++){
        printf("%f\n",NTitik[i]);
  	}
    float f[] = {
         //head
         0.678, -0.331, 0.0,
         0.695, -0.295, 0.0,
         0.697, -0.331, 0.0,
         0.770, -0.348, 0.0,
         0.787, -0.372, 0.0,
         0.715, -0.377, 0.0,
         0.779, -0.393, 0.0,
         0.775, -0.407, 0.0,
         0.699, -0.422, 0.0,
         0.679, -0.408, 0.0,
	};*/
	for(int c=0;c<NTitik.size();c++)
    {
        vertexBufferData[c]=NTitik[c];
        if((c % 3)==0){
            vertexBufferColor[c]= red;
        }
        else if((c % 3)==1){
            vertexBufferColor[c]= green;
        }
        else if((c % 3)==2){
            vertexBufferColor[c]= blue;
        }
        vertexBufferColorBlack[c]=0.0;
    }
    vertexbuffer = 0;
    glGenBuffers(1,&vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexBufferData),vertexBufferData,GL_STATIC_DRAW);

    vertexcolor = 0;
    glGenBuffers(1,&vertexcolor);
    glBindBuffer(GL_ARRAY_BUFFER,vertexcolor);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexBufferColor),vertexBufferColor,GL_STATIC_DRAW);

    //shader
    const char* vertex_shader =
    "#version 400\n"
    "layout(location = 0) in vec3 vertex_position;"
    "layout(location = 1) in vec3 vertex_colour;"
    "out vec3 colour;"
    "void main () {"
    "  colour = vertex_colour;"
    "  gl_Position = vec4 (vertex_position, 1.0);"
    "}";

    const char* fragment_shader =
    "#version 400\n"
    "in vec3 colour;"
    "out vec4 frag_colour;"
    "void main () {"
    "  frag_colour = vec4 (colour, 1.0);"
    "}";

    //load GL shader
    GLuint vs = glCreateShader (GL_VERTEX_SHADER);
    glShaderSource (vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource (fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    //combine shader
    programID = glCreateProgram();
    glAttachShader(programID, fs);
    glAttachShader(programID, vs);
    glLinkProgram(programID);

    return 0;
}

bool my_glObject::display()
{
    // Clear the screen
	//glClear( GL_COLOR_BUFFER_BIT );

	// Use our shader
	glUseProgram(programID);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		NULL            // array buffer offset
	);

    glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vertexcolor);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		NULL            // array buffer offset
	);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLE_FAN, 0, NTitik.size()/3); // 3 indices starting at 0 -> 1 triangle

	//glDisableVertexAttribArray(0);
    //glDisableVertexAttribArray(1);

    return 0;
}



void my_glObject::cleanup()
{
    glDeleteBuffers(1,&vertexbuffer);
    glDeleteBuffers(1,&vertexcolor);
    glDeleteVertexArrays(1,&VertexArrayID);
}
