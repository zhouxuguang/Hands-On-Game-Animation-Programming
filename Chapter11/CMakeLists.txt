set(target chapter11)

set(chapter11_0_SOURCES
	Sample00/Code/XMain.mm
	Sample00/Code/Util.mm
    Sample00/Code/Application.h
    Sample00/Code/Attribute.h
    Sample00/Code/Attribute.cpp
    Sample00/Code/Draw.h
    Sample00/Code/Draw.cpp
    Sample00/Code/glad.h
    Sample00/Code/glad.c
    Sample00/Code/IndexBuffer.h
    Sample00/Code/IndexBuffer.cpp
    Sample00/Code/mat4.h
    Sample00/Code/mat4.cpp
    Sample00/Code/quat.h
    Sample00/Code/quat.cpp
    Sample00/Code/Shader.h
    Sample00/Code/Shader.cpp
    Sample00/Code/stb_image.h
    Sample00/Code/stb_image.cpp
    Sample00/Code/Texture.h
    Sample00/Code/Texture.cpp
    Sample00/Code/Transform.h
    Sample00/Code/Transform.cpp
    Sample00/Code/TransformTrack.h
    Sample00/Code/TransformTrack.cpp
    Sample00/Code/Uniform.h
    Sample00/Code/Uniform.cpp
    Sample00/Code/vec2.h
    Sample00/Code/vec3.h
    Sample00/Code/vec3.cpp
    Sample00/Code/vec4.h
    Sample00/Code/cgltf.h
    Sample00/Code/cgltf.c
    Sample00/Code/Frame.h
    Sample00/Code/GLTFLoader.h
    Sample00/Code/GLTFLoader.cpp
    Sample00/Code/Interpolation.h
    Sample00/Code/Track.h
    Sample00/Code/Track.cpp
    Sample00/Code/Clip.h
    Sample00/Code/Clip.cpp
    Sample00/Code/Pose.h
    Sample00/Code/Pose.cpp
    Sample00/Code/Skeleton.cpp
    Sample00/Code/Skeleton.h
    Sample00/Code/Mesh.cpp
    Sample00/Code/Mesh.h
    Sample00/Code/RearrangeBones.cpp
    Sample00/Code/RearrangeBones.h)

add_executable(chapter11_0 ${chapter11_0_SOURCES})

# 🔗 Link CrossWindow to your project:
target_link_libraries(
    chapter11_0
    CrossWindow
	CrossWindowGraphics
	${OPENGL_LIBRARIES}
)
