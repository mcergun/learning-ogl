CC=gcc
CFLAGS=-I. -Iinclude
LIBS=`pkg-config --libs glfw3 gl` -ldl
DEPS = hellomake.h

main: dirs shaderloader glad
	@${CXX} ${CFLAGS} src/main.cpp obj/glad.o obj/shaderloader.o -o bin/main ${LIBS}

shaderloader: dirs
	@${CXX} ${CFLAGS} src/shaderloader.cpp -c -o obj/shaderloader.o

glad: dirs
	@${CXX} ${CFLAGS} -c src/glad/glad.c -o obj/glad.o

dirs:
	@mkdir -p obj
	@mkdir -p bin

clean:
	@rm -rf bin obj