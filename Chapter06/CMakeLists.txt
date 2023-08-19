set(target chapter06)

set(chapter06_1_SOURCES
	Sample01/Code/XMain.mm
	Sample01/Code/Util.mm
    Sample01/Code/Application.h
    Sample01/Code/Attribute.h
    Sample01/Code/Attribute.cpp
    Sample01/Code/Draw.h
    Sample01/Code/Draw.cpp
    Sample01/Code/glad.h
    Sample01/Code/glad.c
    Sample01/Code/IndexBuffer.h
    Sample01/Code/IndexBuffer.cpp
    Sample01/Code/mat4.h
    Sample01/Code/mat4.cpp
    Sample01/Code/quat.h
    Sample01/Code/quat.cpp
    Sample01/Code/Shader.h
    Sample01/Code/Shader.cpp
    Sample01/Code/stb_image.h
    Sample01/Code/stb_image.cpp
    Sample01/Code/Texture.h
    Sample01/Code/Texture.cpp
    Sample01/Code/Transform.h
    Sample01/Code/Transform.cpp
    Sample01/Code/Uniform.h
    Sample01/Code/Uniform.cpp
    Sample01/Code/vec2.h
    Sample01/Code/vec3.h
    Sample01/Code/vec3.cpp
    Sample01/Code/vec4.h
    Sample01/Code/Sample.h
    Sample01/Code/Sample.cpp)

add_executable(chapter06_1 ${chapter06_1_SOURCES})

# 🔗 Link CrossWindow to your project:
target_link_libraries(
    chapter06_1
    CrossWindow
	CrossWindowGraphics
	${OPENGL_LIBRARIES}
)
