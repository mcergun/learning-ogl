CC=gcc
CFLAGS=-I. -Iinclude -Iglm -Wall
LIBS=`pkg-config --libs glfw3 gl` -ldl
DEPS = hellomake.h

main: dirs glad Shader Texture Drawer
	${CXX} ${CFLAGS} src/main.cpp obj/glad.o obj/Shader.o obj/Texture.o obj/Drawer.o -o bin/main ${LIBS}

Shader: dirs
	${CXX} ${CFLAGS} src/Shader.cpp -c -o obj/Shader.o

Texture: dirs
	${CXX} ${CFLAGS} src/Texture.cpp -c -o obj/Texture.o

Drawer: dirs
	${CXX} ${CFLAGS} src/Drawer.cpp -c -o obj/Drawer.o

glad: dirs
	${CXX} ${CFLAGS} -c src/glad/glad.c -o obj/glad.o

dirs:
	@mkdir -p obj
	@mkdir -p bin

clean:
	@rm -rf bin obj