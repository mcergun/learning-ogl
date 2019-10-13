CC=gcc
CFLAGS=-I. -Iinclude
LIBS=`pkg-config --libs glfw3 gl` -ldl
DEPS = hellomake.h

main: dirs glad
	@${CXX} ${CFLAGS} src/main.cpp obj/glad.o -o bin/main ${LIBS}

glad: dirs
	@${CXX} ${CFLAGS} -c src/glad/glad.c -o obj/glad.o

dirs:
	@mkdir -p obj
	@mkdir -p bin

clean:
	@rm -rf bin obj