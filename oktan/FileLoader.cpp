#include <fstream>
#include <sstream>
#include "FileLoader.h"

namespace oktan
{
    int32_t FileLoader::ReadFile(std::string filePath, std::string & outFileContent)
    {
        int32_t ret = 0;
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream ifs;
        ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            ifs.open(filePath);
            std::stringstream ss;
            ss << ifs.rdbuf();
            ifs.close();
            outFileContent = ss.str();
            ss.str("");
            ss.clear();
        }
        catch(const std::exception& e)
        {
            OK_LOG_CRIT("Exception while reading {}, {}!", filePath, e.what());
            ret = -1;
        }
        return ret;
    }
}