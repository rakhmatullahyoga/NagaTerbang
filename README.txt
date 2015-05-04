The files relating to GLEW and instructions how to use them are inside the glew files folder.
I would suggest following the video and learn how to compile them yourself also. That way when a new version comes out you can up date yours.

Settings:
Under settings>Linker settings
-lmingw32 -lSDL2main -lSDL2 -lSDL2_image
-lopengl32 -lglu32 -lglew32 -lglew32mx


Under: settings>Search directories>Compiler
C:\SDL\SDL2-2.0.2\i686-w64-mingw32\include\SDL2
C:\SDL\SDL2_image-2.0.0\i686-w64-mingw32\include\SDL2


Under: settings>Search directories>Linker
C:\SDL\SDL2-2.0.2\i686-w64-mingw32\lib
C:\SDL\SDL2_image-2.0.0\i686-w64-mingw32\lib


My includes are
#include <SDL.h>
#include <SDL_image.h>
#include <GL/glew.h>



if you change 
C:\SDL\SDL2-2.0.2\i686-w64-mingw32\include\SDL2
to
C:\SDL\SDL2-2.0.2\i686-w64-mingw32\include\
the include would need to be changed to
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>