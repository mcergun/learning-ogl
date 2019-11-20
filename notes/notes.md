# Learning OpenGL

## OpenGL Drawing Scheme

In OpenGL everything is in 3D. Everything is transformed into 2D before they are drawn onto the screen.

The transformation process is handled by the __graphics pipeline__ of OpenGL. The pipeline consists of many small programs that are called __shaders__.

Some shaders can be replaced by the programmers:

- Vertex Shaders
- Geometry Shaders
- Fragment Shaders

The shaders are written in _OpenGL Shading Language(GLSL)_.

The pipeline can be simplified as:

> Vertex Data -> Vertex Shader -> Shape Assembly -> Geometry Shader -> Rasterization -> Blending -> Fragment Shader

__Vertex data__ is a collection of vertices. A __vertex__ is basically a collection of data per 3D coordinate. The vertex can contain any data along with its 3D position.

> Does the programmer want the vertices to be drawn as triangles, lines, simple points? To answer these kinds of questions, OpenGL needs some hints from the programmer. Those hints are called __primitives__ and are given to OpenGL while calling the drawing commands. Some of those hints are `GL_POINTS`, `GL_TRIANGLES`, `GL_LINE_STRIP`.

__Vertex Shader__ stage is used to transform 3D coordinates into other 3D coordinates. It also allows the programmer to do some basic processing on the vertex attributes.

__Primitive Assembly__ stage assembles vertices according to the hints provided by the programmer.

__Geometry Shader__ stage takes primitively shaped vertice collections and creates other complex shapes by emitting other vertices.

__Rasterization Stage__ is where shapes are mapped into pixels on the final screen. The output is called fragments which will be used by fragment shader. This stage also clips unneeded primitives that are out of the view to increase performance.

__Fragment Shader__ stage calculates the final color of the pixel. This stage is mainly used for fancy effects.

__Alpha Test and Blending__ stage is the final stage that checks corresponding depth value of the fragments and calculates which fragments are in the front or behind. This information together with the alpha values changes pixel's final value.

OpenGL requires programmers to define their own Vertex and Fragment Shaders. To draw something, I must learn GLSL and define my first two shaders (Yay!!).

### Generating OpenGL Buffers

- Generate a buffer id with `glGenBuffer`
- Bind generated buffer with a role `glBindBuffer`. Used `GL_ARRAY_BUFFER` for vertex attributes
- Transfer data to OGL buffer with `glBufferData`. Again, used `GL_ARRAY_BUFFER` as mode, and `GL_STATIC_DRAW` as the usage.
    - `GL_STATIC_DRAW`: the data will most likely not change at all or very rarely.
    - `GL_DYNAMIC_DRAW`: the data is likely to change a lot.
    - `GL_STREAM_DRAW`: the data will change every time it is drawn.

### Creating and Compiling a Vertex/Fragment Shader

- Generate a shader id with `glCreateShader`. Used `GL_VERTEX_SHADER` and `GL_FRAGMENT_SHADER` as shaderType.
- Assign shader source with `glShaderSource`. 
- Compile shader with `glCompileShader`.

### Creating Shader Program
- Generate a shader program with `glCreateProgram`.
- Attach vertex and fragment shaders with `glAttachShader`.
- Link the program with `glLinkProgram`.
- Use the program with `glUseProgram`.
- Remove attached shaders with `glDeleteShader`.

### Creating a Vertex Array Object
- Generate a vertex array with `glGenVertexArrays`.
- Bind it using `glBindVertexArray`

> ### Difference between Vertex Buffer and Vertex Array Objects, __VBO vs VAO__
> Vertex buffer is a buffer to store vertex attributes on GPU memory. `glBindBuffer` `glBufferData` and `glVertexAttribPointer` functions tell OpenGL how to use the attributes.<p>
Vertex array objects on the other hand, stores related vertex buffer objects or _similar stuff_ together in a packet and allows the programmer to quickly change those states.

### Arranging Buffers pt2
After introducing Vertex Array Objects, things got a little different. New flow is like this:
- Generate a Vertex Array Object (VAO) with `glGenVertexArrays`.
- Generate a Vertex Buffer Object (VBO) with `glGenBuffers`.
- Bind vao with `glBindVertexArray`.
- Bind vbo as `GL_ARRAY_BUFFER` using `glBindBuffer`.
- Transfer buffer data to vbo with `glBufferData`, use `GL_STATIC_DRAW` for static objects like ours.
- Assign vertex attributes with `glVertexAttribPointer`.
- Use `glEnableVertexAttribArray` to enable attribute array we just registered.

> #### glVertexAttribPointer
> This function takes a whole lot of parameters:
> - _index_, index of the pointer. This is OpenGL's internal index.
> - _size_, this is a little confusing, it is actually dimension count. 3 positions for our vertices.
> - _type_, we used float, thus `GL_FLOAT` fits here. OpenGL uses float for its internals.
> - _normalized_, we used [-1.0f, 1.0f] range for our vertices. No need for normalization. Use `GL_FALSE` here.
> - _stride_, number of bytes between each vertex's data. We have 3 positions on 3 axes, thus `3 * sizeof(float)` is our stride size. We could also use `0` as our vertices are tightly packed. (no additional data between vertices)
> - _pointer_, this is confusing as well. This parameter is actually an offset to our buffer data transferred via `glBufferData`. So we will use `0`.
