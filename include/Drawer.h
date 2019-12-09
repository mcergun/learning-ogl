#ifndef _DRAWER_H_
#define _DRAWER_H_

#include <vector>

enum DrawerPrimitiveTypes
{
    DrawerType_Int = 0x1404,
    DrawerType_UnsignedInt = 0x1405,
    DrawerType_Float = 0x1406,
};

class Drawer
{
public:
    Drawer();

    void AddVertexArray();
    void AddVertexBuffer(void *buf, unsigned int size, unsigned int stride);
    void AddIndexBuffer(unsigned int *buf, unsigned int size, unsigned int stride);

    void BindVertexArray(unsigned int idx = 0);
    void BindVertexBuffer(unsigned int idx = 0);
    void BindIndexBuffer(unsigned int idx = 0);

    void AddVertexAttribute(unsigned int index, DrawerPrimitiveTypes type, unsigned int count, bool normalize, unsigned int stride, unsigned int offset);

    void DeleteVertexArrays();
    void DeleteVertexBuffers();
    void DeleteIndexBuffers();

    void DrawArrays();
    void DrawElements();

private:
    std::vector<unsigned int> VAOList;
    std::vector<unsigned int> VBOList;
    std::vector<unsigned int> EBOList;

    std::vector<unsigned int> VBOSizeList;
    std::vector<unsigned int> EBOSizeList;

    unsigned int ActiveIdx = 0;
};

#endif