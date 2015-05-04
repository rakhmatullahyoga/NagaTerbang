#include "loadtextfile.h"

std::string LoadTextFromFile(std::string path)
{
    std::ifstream sourceFile( path.c_str(), std::ios::in );
    if( sourceFile.is_open() )
	{
	    std::string content;
        content.assign( ( std::istreambuf_iterator< char >( sourceFile ) ), std::istreambuf_iterator< char >() );
        sourceFile.close();
        return content;
	}
	else
    {
        return "error";
    }
}
