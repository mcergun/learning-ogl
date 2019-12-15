#include <iostream>
#include "OGLBufferLayout.h"
#include "OGLVertexBuffer.h"
#include "OGLIndexBuffer.h"

int main(int argc, char **argv)
{
    // drawer.AddVertexAttribute(0, DrawerType_Float, 3, false, 5 * sizeof(float), 0);
	// drawer.AddVertexAttribute(1, DrawerType_Float, 2, false, 5 * sizeof(float), 3 * sizeof(float));
    oktan::OGLBufferLayout oglbl({
        {oktan::BaseType::Float, 3, false},
        {oktan::BaseType::Float, 2, false}
        });
    for (auto &&e : oglbl.m_Elements)
    {
        std::cout << e.Offset << ", " << e.Count << ", " << std::endl;
    }
    
    
    
    std::cout << "hello world!" << std::endl;
}