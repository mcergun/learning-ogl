#ifndef _DRAWER_H_
#define _DRAWER_H_

#include <vector>

class Drawer
{
public:
    Drawer();

    void AddVertexArray();
    void AddVertexBuffer(void *buf, unsigned int size);
    void AddIndiceBuffer(unsigned int *buf, unsigned int size);

    void BindVertexArray(unsigned int idx = 0);
    void BindVertexBuffer(unsigned int idx = 0);
    void BindIndiceBuffer(unsigned int idx = 0);

    void DeleteVertexArrays();
    void DeleteVertexBuffers();
    void DeleteIndiceBuffers();

private:
    std::vector<unsigned int> VAOList;
    std::vector<unsigned int> VBOList;
    std::vector<unsigned int> EBOList;
};

#endif