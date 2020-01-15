#ifndef _OK_OGL_VERTEX_ARRAY_H_
#define _OK_OGL_VERTEX_ARRAY_H_

#include <oktan/renderer/VertexArray.h>

namespace oktan
{
    class OGLVertexArray : public VertexArray
    {
    public:
        OGLVertexArray();
        virtual void Bind() const override;
        virtual void Unbind() const override;
        virtual void AddIndexBuffer(IndexBuffer *ebo) override;
        virtual void AddIndexBuffer(uint32_t *data, uint32_t size) override;
        virtual void AddVertexBuffer(VertexBuffer *vbo) override;
        virtual void AddVertexBuffer(float *data, uint32_t size) override;
    };
}

#endif