CC=gcc
CFLAGS=-I. -Iinclude -Wall
LIBS=`pkg-config --libs glfw3 gl` -ldl
DEPS = hellomake.h

main: dirs glad Shader
	${CXX} ${CFLAGS} src/main.cpp obj/glad.o obj/Shader.o -o bin/main ${LIBS}

Shader: dirs
	${CXX} ${CFLAGS} src/Shader.cpp -c -o obj/Shader.o

glad: dirs
	${CXX} ${CFLAGS} -c src/glad/glad.c -o obj/glad.o

dirs:
	@mkdir -p obj
	@mkdir -p bin

clean:
	@rm -rf bin obj