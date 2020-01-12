#ifndef _OK_FILELOADER_H_
#define _OK_FILELOADER_H_

#include <string>

#include "Core.h"

namespace oktan
{
    class FileLoader
    {
    public:
        static int32_t ReadFile(std::string filePath, std::string & outFileContent);
    };
}

#endif