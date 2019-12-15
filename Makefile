CC=gcc
CFLAGS=-I. -Ioktan -Ioktan/vendor -Ioktan/vendor/glm -Ioktan/vendor/stb -Wall
LIBS=`pkg-config --libs glfw3 gl` -ldl
DEPS = hellomake.h

main: dirs glad Shader Texture Drawer ogl
	${CXX} ${CFLAGS} oktan/main.cpp obj/glad.o obj/Shader.o obj/Texture.o obj/Drawer.o -o bin/main ${LIBS}

Shader: dirs
	${CXX} ${CFLAGS} oktan/Shader.cpp -c -o obj/Shader.o

Texture: dirs
	${CXX} ${CFLAGS} oktan/Texture.cpp -c -o obj/Texture.o

Drawer: dirs
	${CXX} ${CFLAGS} oktan/Drawer.cpp -c -o obj/Drawer.o

glad: dirs
	${CXX} ${CFLAGS} -c oktan/vendor/glad/glad.c -o obj/glad.o

main2: dirs ogl glad
	${CXX} ${CFLAGS} oktan/platform/opengl/main.cpp obj/glad.o obj/OGLBufferLayout.o obj/OGLIndexBuffer.o obj/OGLVertexBuffer.o -o bin/main2 ${LIBS}

ogl:
	${CXX} ${CFLAGS} -c oktan/platform/opengl/OGLIndexBuffer.cpp -o obj/OGLIndexBuffer.o
	${CXX} ${CFLAGS} -c oktan/platform/opengl/OGLVertexBuffer.cpp -o obj/OGLVertexBuffer.o
	${CXX} ${CFLAGS} -c oktan/platform/opengl/OGLBufferLayout.cpp -o obj/OGLBufferLayout.o

dirs:
	@mkdir -p obj
	@mkdir -p bin

clean:
	@rm -rf bin obj