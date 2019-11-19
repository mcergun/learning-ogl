#include <fstream>
#include <sstream>
#include <shaderloader.h>
#include <iostream>

std::string getShader(const std::string path)
{
    std::string ret;
    std::ifstream ifs;
    ifs.open(path, std::ios_base::in);
    // char * buf = nullptr;
    if (ifs.is_open())
    {
        std::ostringstream oss;
        oss << ifs.rdbuf();
        ret = oss.str();
        ifs.close();
    }
    return ret;
}