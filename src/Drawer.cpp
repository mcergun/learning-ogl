#include <Drawer.h>
#include <glad/glad.h>

	// unsigned int vao;
	// unsigned int vbo;
	// unsigned int ebo;
	// glGenVertexArrays(1, &vao);
	// glBindVertexArray(vao);
	// glGenBuffers(1, &vbo);
	// glGenBuffers(1, &ebo);

	// glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
#include <cstdio>
Drawer::Drawer()
{
    VAOList = std::vector<unsigned int>();
    VBOList = std::vector<unsigned int>();
    EBOList = std::vector<unsigned int>();
}

void Drawer::AddVertexArray()
{
    unsigned int id = 0;
    glGenVertexArrays(1, &id);
    VAOList.push_back(id);
    printf("New vertex array %d\r\n", id);
}

void Drawer::AddVertexBuffer(void *buf, unsigned int len)
{
    unsigned int id = 0;
    glGenBuffers(1, &id);
    VBOList.push_back(id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, len, buf, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    printf("New vertex buffer %d\r\n", id);
}

void Drawer::AddIndiceBuffer(unsigned int *buf, unsigned int len)
{
    unsigned int id = 0;
    glGenBuffers(1, &id);
    EBOList.push_back(id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, len, buf, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    printf("New indice buffer %d\r\n", id);
}

void Drawer::BindVertexArray(unsigned int idx)
{
    glBindVertexArray(VAOList[idx]);
}

void Drawer::BindVertexBuffer(unsigned int idx)
{
    glBindBuffer(GL_ARRAY_BUFFER, VBOList[idx]);
    printf("binding vertex buffer %d\r\n", VBOList[idx]);
}

void Drawer::BindIndiceBuffer(unsigned int idx)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOList[idx]);
    printf("binding indice buffer %d\r\n", EBOList[idx]);
}

void Drawer::DeleteVertexArrays()
{
    for (unsigned int i = 0; i < VAOList.size(); i++)
    {
        glDeleteVertexArrays(1, &VAOList[i]);
    }
    VAOList.clear();
}

void Drawer::DeleteVertexBuffers()
{
    for (unsigned int i = 0; i < VBOList.size(); i++)
    {
        glDeleteVertexArrays(1, &VBOList[i]);
    }
    VBOList.clear();
}

void Drawer::DeleteIndiceBuffers()
{
    for (unsigned int i = 0; i < EBOList.size(); i++)
    {
        glDeleteVertexArrays(1, &EBOList[i]);
    }
    EBOList.clear();
}
